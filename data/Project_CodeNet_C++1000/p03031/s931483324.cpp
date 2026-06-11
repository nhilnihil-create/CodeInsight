#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
using namespace std;
using ll = unsigned long long;
using p = pair<int, int>;

int main()
{
    int N, M;
    cin >> N >> M;

    int p = 0;

    // スイッチがどの電球と接続しているかをbitで持つ
    vector<int> connect(N);

    rep(i, 0, M)
    {
        int k;
        cin >> k;

        rep(j, 0, k)
        {
            int s;
            cin >> s;
            --s; // 0から数えた方が処理書きやすいので
            connect[s] |= (1 << i);
        }
    }

    rep(i, 0, M)
    {
        int x;
        cin >> x;
        p |= (x << i);
    }

    int ans = 0;

    // 全通りのスイッチのon/offのパターンを調べる
    rep(i, 0, (1 << N))
    {
        // 電球のon/offをbitで表現
        int t = 0;
        rep(j, 0, N)
        {
            if ((i >> j) & 1)
            {
                t ^= connect[j];
            }
        }
        // tのbitが1の時、スイッチは奇数個
        // tのbitが0の時、スイッチは偶数個
        // tにはスイッチ数で割った結果がこの段階で入っている
        // なのでpとそのまま比較することで、結果の検討ができる
        if (t == p)
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}

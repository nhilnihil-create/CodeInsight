#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int N, M;
void func()
{
    cin >> N >> M;
    pair<int, int> ba[M];
    rep(i, 0, M)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        ba[i] = make_pair(tmp2, tmp1);
    }
    sort(&ba[0], &ba[M]);
    int ans = 0;
    int i = 0;
    while (i < M)
    {
        int j = 1;
        while (ba[i].first > ba[i + j].second && i + j < M)
            ++j;
        ++ans;
        i += j;
    }
    cout << ans << endl;
}
int main()
{
    func();
}
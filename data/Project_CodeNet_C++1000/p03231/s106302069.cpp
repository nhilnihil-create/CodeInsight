#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N, M, L;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;
    L = N / __gcd(N, M) * M;
    bool ok = 1;
    // L の長さが決まると,Xの特定の場所の文字が決まる
    map<ll, char> mp;
    for (int i = 0; i < N; i++)
    {
        mp[1 + (i)*(L / N)] = S[i];
    }
    for (int i = 0; i < M; i++)
    {
        if (mp.count((1 + (i)* (L / M))))
        {
            if (mp[1 + (i)*(L / M)] != T[i])
                ok = 0;
        }
    }
    if (ok)
        cout << L << endl;
    else
        cout << -1 << endl;
}
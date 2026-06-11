#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        ll N, K; cin >> N >> K;
        ll ans = 1;
        for (int i = 0; i < N; ++i) {
                ll tmp1 = ans * 2;
                ll tmp2 = ans + K;
                if (tmp1 < tmp2) ans = tmp1;
                else ans = tmp2;
        }
        cout << ans << endl;




}

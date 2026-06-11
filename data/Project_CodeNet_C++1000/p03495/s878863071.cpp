#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int (i)=0; (i)<(n); (i)++)

int main()
{
        ll N, K; cin >> N >> K;
        map<ll, ll> m;
        rep(i, N) {
                ll tmp; cin >> tmp;
                m[tmp]++;
        }
        ll cnt = K - m.size();
        ll ans = 0;
        vector<ll> V;
        for (auto i : m) {
                V.push_back(i.second);
        }
        sort(V.begin(), V.end());
        rep (i, V.size()) {
                if (cnt >= 0) {
                        break;
                }
                ans += V[i];
                cnt++;
        }
        cout << ans << endl;
}

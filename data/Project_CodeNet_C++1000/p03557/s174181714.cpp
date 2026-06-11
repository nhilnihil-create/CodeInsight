#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        ll N; cin >> N;
        vector<ll> A(N, 0);
        vector<ll> B(N, 0);
        vector<ll> C(N, 0);
        for (int i = 0; i < N; ++i) {
                cin >> A[i];
        }
        for (int i = 0; i < N; ++i) {
                cin >> B[i];
        }
        for (int i = 0; i < N; ++i) {
                cin >> C[i];
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        sort(C.begin(), C.end());

        ll ans = 0;
        for (int i = 0; i < N; ++i) {
                ll tmp = B[i];
                auto it1 = lower_bound(A.begin(), A.end(), tmp);
                ll tmp1 = it1 - A.begin();
                auto it2 = upper_bound(C.begin(), C.end(), tmp);
                ll tmp2 = C.end() - it2;
                tmp1 *= tmp2;
                ans += tmp1;
        }
        cout << ans << endl;


}

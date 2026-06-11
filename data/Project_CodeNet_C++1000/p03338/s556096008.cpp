#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int (i)=0; (i) < (n); (i)++)

int main()
{
    ll N; cin >> N;
    string S; cin >> S;

    ll ans = 0;
    rep(i, N) {
            vector<ll> A(26, 0);
            vector<ll> B(26, 0);
            rep(j,N) {
                if (j < i+1) {
                    A[S[j] - 'a'] = 1;
                    //cout << "A = " << S[j] << endl;
                }
                else {
                    B[S[j] - 'a'] = 1;
                    //cout << "B = " << S[j] << endl;
                }
            }
            ll num = 0;
            rep(j, 26) {
                if (A[j] == 1 && B[j] == 1) num++;
            }
            if (ans < num) ans = num;
    }
    cout << ans << endl;

    




}

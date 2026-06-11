#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define D1(a) cerr<<#a<<":"<<a<<endl
#define D2(a,b) cerr<<#a<<":"<<a<<","<<#b<<":"<<b<<endl
#define D3(a,b,c) cerr<<#a<<":"<<a<<","<<#b<<":"<<b<<","<<#c<<":"<<c <<endl
#define D4(a,b,c,d) cerr<<#a<<":"<<a<<","<<#b<<":"<<b<<","<<#c<<":"<<c<<","<<#d<<":"<<d<<endl
#define DH(c) do{rep(__i, c.size())cerr<<c[__i]<<(__i==c.size()-1?'\n':' ');}while(0)

int main()
{
    ll K; cin >> K;
    vector<ll> A(K); for (auto& a : A) cin >> a;

    ll l = 2, r = 2;
    for (int i = K-1; i >= 0; i--) {
        if (r/A[i] - (l-1)/A[i] == 0) {
            l = -1;
            break;
        }
        l = A[i] * ((l+A[i]-1)/A[i]);
        r = A[i] * (r/A[i]) + A[i] - 1;
        // D2(l, r);
    }

    if (l == -1) {
        cout << -1 << endl;
    } else {
        cout << l << " " << r << endl;
    }
}

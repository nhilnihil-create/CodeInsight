#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int (i)=0; (i) < (n); (i)++)

int main()
{
    ll A, B, C; cin >> A >> B >> C;
    ll K; cin >> K;
    ll sum = A + B + C;
    ll maxv = max(A, B);
    maxv = max(maxv, C);
    sum -= maxv;
    rep(i,K) {
        maxv *= 2;
    }
    cout << sum + maxv << endl;

 
    




}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

int main()
{
    ll N; cin >> N;
    vector<ll> a(N, 0);
    ll sum = 0;
    rep(i,N) {
        ll t; cin >> t;
        a[i] = t;
        sum += t;
    }
    cout << sum - N << endl;


    

}

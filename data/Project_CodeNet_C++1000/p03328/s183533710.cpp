#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int (i)=0; (i) < (n); (i)++)

int main()
{
    ll a, b; cin >> a >> b;
    ll dif = b - a;
    ll sum = 0;
    rep(i,dif-1) {
        sum += (i+1);
    }
    cout << sum - a << endl;

 

}

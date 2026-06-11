#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int (i)=0; (i) < (n); (i)++)

int main()
{
    ll K; cin >> K;
    if (K % 2 == 0) {
        cout << K / 2 * K / 2 << endl;
    }
    else {
        ll tmp = (K - 1) / 2;
        cout << (tmp+1) * tmp << endl;
    }



}

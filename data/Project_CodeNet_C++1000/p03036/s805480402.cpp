#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    int r, D, x;
    cin >> r >> D >> x;
    ll a = r*x-D;
    cout << a << endl;
    for(int i=0; i<9; ++i){
        cout << r*a-D << endl;
        a = r*a-D;
    }
    return 0;

}

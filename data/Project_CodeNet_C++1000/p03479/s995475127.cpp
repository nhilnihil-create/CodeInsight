#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main(){
    ll x, y, i = 1;
    cin >> x >> y;
    while(x * 2 <= y){
        x *= 2;
        i++;
    }
    cout << i << endl;
}
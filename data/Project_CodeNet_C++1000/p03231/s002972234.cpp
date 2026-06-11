#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<numeric>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
//int gcd ( int a, int b ) {
//    if ( a % b == 0 ) return b;
//    return gcd( b, a % b);
//}
//int lcm ( int a, int b ) {
//    return a * b / gcd(a, b);
//}
int main(){
    ll n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    ll gcd_num = __gcd(n, m);
//    int lcm_num = lcm(n, m);
    ll _n = n / gcd_num;
    ll _m = m / gcd_num;
    for ( int i = 0; i < gcd_num; ++i ) {
        if ( s[i*_n] != t[i*_m] ) {
            puts("-1");
            return 0;
        }
    }
    cout << _n * _m * gcd_num << endl;
    return 0;
}
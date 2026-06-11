#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int inf = 1001001001;
 
int main(){

    ll r,d,x;
    cin >> r >> d >> x;
    rep(i,10){
        cout << r*x-d << endl;
        x=r*x-d;
    }
 
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int inf = 1001001001;
const long long max=1000000007;

int main(){
    ll a,b,c,k;
    cin >> a >> b >> c >> k;
    if(k%2==1){
        cout << b-a << endl;
    }
    else{
        cout << a-b << endl;
    }
}
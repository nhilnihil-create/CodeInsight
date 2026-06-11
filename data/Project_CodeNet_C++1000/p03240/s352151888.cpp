#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<ll>X(n), Y(n), h(n);
    int a=-1, b=-1;
    ll c=-1;
    rep(i, 0, n)cin >> X[i] >> Y[i] >> h[i];
    rep(x, 0, 101){
        rep(y, 0, 101){
            bool flag = true;
            ll temph;
            rep(i, 0, n){
                if(h[i]==0)continue;
                temph = h[i]+abs(X[i]-x)+abs(Y[i]-y);
                break;
            }
            rep(i, 0, n){
                if(h[i]!=max((temph-(abs(X[i]-(ll)x)+abs(Y[i]-(ll)y))),(ll)0))flag = false;
            }
            if(flag){
                a = x;
                b = y;
                c = temph; 
                cout << a << " " << b << " " << c << endl;
                return 0;
            }
        }
    }
}
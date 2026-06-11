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

ll xorp(ll p){
    ll q  = (p+1)/2; 
    if((p+1)%2==1){
        if(q%2==1){
            ll ans = 1^p;
            return ans;
        }else{
            ll ans = 0^p;
            return ans;
        }
    }else{
        if(q%2==1){
            ll ans = 1;
            return ans;
        }else{
            ll ans = 0;
            return ans;
        }
    }
}

int main(){
  ll a, b;
  cin >> a >> b;
  ll res =  xorp(b)^xorp(a-1);
  cout << res << endl;
}
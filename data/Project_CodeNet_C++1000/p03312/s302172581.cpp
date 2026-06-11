#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
typedef pair<int,int> P;
const int MOD = 1000000007;
const ll INF = 1e10;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 
#define int long long
#define double long double



////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////i

int n, a[210000], ac[210000];
signed main(){
  cin>>n;rep(i,n)cin>>a[i];
  int ans = INF;
  rep(i,n)ac[i+1] = ac[i]+a[i];
  repd(i,2,n-1){//B->[0, b), C->[b, i), D->[i, d), E->[d, n) 

    int lmin = INF, lmax = -INF, rmin = INF, rmax = -INF;
    auto p = lower_bound(ac, ac+i, ac[i]/2), r = lower_bound(ac+i, ac+n+1, (ac[n]+ac[i])/2);
    repd(k, -1, 2){
      lmin = min(*(p+k), ac[i]-*(p+k));
      lmax = max(*(p+k), ac[i]-*(p+k));
      repd(j,-1,2){
        rmin = min(*(r+j) - ac[i], ac[n]-*(r+j));
        rmax = max(*(r+j) - ac[i], ac[n]-*(r+j));
        chmin(ans, max(lmax, rmax) - min(lmin, rmin));
      }
    }
    
  }
  cout << ans << endl;
}




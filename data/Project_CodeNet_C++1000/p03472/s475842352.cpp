#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);++i)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
  
const int MOD=1e9+7;
const ll INF=1e18;
const ll inf=1e9;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
 
const int MAX=510000;


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
   
  ll n,h;
  cin >> n >> h;
  vector<ll> a(n),b(n);
  rep(i,n) cin >> a[i] >> b[i];
  
  sort(a.begin(),a.end(),greater<ll>());
  sort(b.begin(),b.end(),greater<ll>());
  
  vector<ll>s(n+1);
  ll num = 0;
  rep(i,n){
    if(b[i]>a[0]){
      s[i+1] = s[i] + b[i];
      num++;
    }
    else break;
  }
  
  ll ok = inf, ng = 0;
  while(abs(ok-ng)>1){
    ll mid = (ok+ng)/2;
    
    if(mid*a[0]>=h) ok=mid;
    else{
      if(mid<=num){
        if(s[mid]<h)ng=mid;
        else ok = mid;
      }
      else{
        if(s[num]+(mid-num)*a[0]<h)ng=mid;
        else ok = mid;
      }
    }
  }
  cout << ok << endl;
  return 0;
}

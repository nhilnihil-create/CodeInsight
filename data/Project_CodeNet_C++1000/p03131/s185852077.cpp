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
   
  ll k,a,b;
  cin >> k >> a >> b;
  ll now = 1;
  if(a+2>=b)now+=k;
  else{
    while(k>0){
      if(now<a){
        if(a-now+2>k){
          now += k;
          break;
        }
        else{
          k -= (a-now+2);
          now = b;
        }
      }
      else{
        if(k<2){
          now += k;
          break;
        }
        else{
          k-=2;
          now += b-a;
        }
      }
    }
  }
  
  cout << now << endl;
  return 0;
}

#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);++i)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};


const int MAX=3000;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  int n,k;
  cin >> n >> k;
  vector<int>vec(n);
  rep(i,n) cin >> vec[i];
  ll ans = 0;
  for(int i=1;i<=min(n,k);i++){
    for(int a=0;a<=i;a++){
      int b=i-a;
      priority_queue<int,vector<int>,greater<int>>q;
      ll sum=0;
      rep(j,a){
        q.push(vec[j]);
        sum += vec[j];
      }
      rep(j,b){
        q.push(vec[n-1-j]);
        sum += vec[n-1-j];
      }
      int res = k-i;
      while(res>0 && !q.empty()){
        int t=q.top();
        if(t<0){
          sum -= t;
          q.pop();
          res--;
        }
        else break;
      }
      ans=max(ans,sum);
    }
  }
  cout << ans << endl;
  return 0;
}
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
 
const int MAX=510000;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
   
  
  int n, k;
  cin >> n >> k;
  vector<int>vec(n);
  rep(i,n) cin >> vec[i];
  
  int ans = 0;
  for(int tot=1;tot<=min(n,k);tot++){
    for(int left=0;left<=tot;left++){//決めた
      int right = tot-left;
      priority_queue<int,vector<int>,greater<int>>que;
      int sum = 0;
      rep(i,left){
        que.push(vec[i]);
        sum += vec[i];
      }
      rep(i,right){
        que.push(vec[n-1-i]);
        sum += vec[n-1-i];
      }
      int res = k-tot;
      while(res && !que.empty()){
        int t = que.top();
        if(t>=0)break;
        res--;
        que.pop();
        sum -= t;
      }
      chmax(ans,sum);
    }
  }
  cout << ans << endl;
          
  return 0;
}

#include<bits/stdc++.h>
using namespace std;
    static const double pi = 3.141592653589793;
 typedef pair<int64_t,int64_t> P;
#define rep(i, n) for (int i = 0; i < (n); i++)
 #define all(v) (v).begin(),(v).end()
 using ll = long long;
using Graph = vector<vector<int>>;
const int MAX = 510000;
const int MOD = 1000000007;
 const int NINE=1000000000;
 
 
int main(){
ll N;
  cin>>N;
  vector<ll>op(N);
  vector<ll>ans(N);
  ll g=0;
  rep(i,N){
 ll p;
    cin>>p;
    op[i]=p;
  }
  for(int i=N-1;i>=0;i--){
  ll t=-1;
    ll count=0;
  ll h=op[i];
    while(count!=h){
    t++;
      if(t==N){
        break;
      g=1;
      }
      if(ans[t]==0){
      count++;
      
      }
    
    }
    ans[t]=h;
   
  if(g==1) break;
  }
   rep(i,N) if(ans[i]==0) g=1;
  if(g==0){
  rep(i,N){
  cout<<ans.at(i)<<endl;
  
  }
  }
  else cout<<-1;
  
  
  
  
  
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;



int main(){
  ll n,K;
  cin >> n >> K;
  vector<ll>v(n);
  for(int i=0; i<n; i++) cin >> v[i];
  
  
  ll a = min(n,K);
  
  ll ans = 0;
  for(int i=1; i<=a; i++){
    for(int j=0; j<=i; j++){
      priority_queue<ll,vector<ll>,greater<ll>>pq;
      ll count = K-i;
      ll res = 0;
      for(int k=0; k<j; k++){
        pq.push(v[k]);
        res+=v[k];
        //cout << res << " ";
      }
      for(int l=0; l<i-j; l++){
        pq.push(v[n-1-l]);
        res+=v[n-1-l];
        //cout << res << " ";
      }
      
      while(count){
        if(pq.top()<0){
          //cout << pq.top() << " ";
          ll x = pq.top();
          pq.pop();
          res-=x;
        }
        count--;
        if(pq.size()==0)break;
      }
      
      ans = max(ans,res);
      //cout << res << endl;
    }
  }
  
  cout << ans << endl;
  
}
       
        
      
  
    

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main(){
  ll n;
  cin >> n;
  vector<ll>a(n),b(n);
  for(int i=0; i<n ;i++) cin >> a[i];
  for(int i=0; i<n; i++) cin >> b[i];
  
  vector<ll>d(n);
  for(int i=0; i<n; i++) d[i] = a[i] - b[i];
  
  ll counta = 0;
  for(int i=0; i<n; i++){
    if(d[i]<0){
      if(-1*d[i]%2==1) counta += -1*d[i]/2+1;
      else counta += -1*d[i]/2;
      d[i] = -1*d[i]%2;
    }
  }
  
  ll countb = 0;
  for(int i=0; i<n; i++){
    countb+=d[i];
  }
  
  if(counta-countb>=0) cout << "Yes" << endl;
  else cout << "No" << endl;
  
}
       
        
      
  
    

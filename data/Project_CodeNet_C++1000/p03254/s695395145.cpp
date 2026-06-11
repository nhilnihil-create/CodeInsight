#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll N,x;
  cin >> N >> x;
  vector<ll> a(N);
  for(ll i=0;i<N;i++){
    cin >> a[i];
  }
  ll y=x;
  
  sort(a.begin(),a.end());
  
  ll ans=0;
  
  for(ll i=0;i<N;i++){
    x=x-a[i];
    ans++;
    
    if(x==0){
      break;
    }
    else if(x<0){
      ans=ans-1;
      break;
    }
  }
  
  ll sum;
  
  for(ll i=0;i<N;i++){
    sum=sum+a[i];
  }

    
  
  if(y>sum){
    cout << N-1 << endl;
  }
  
  else{  
    cout << ans << endl;
  }

}

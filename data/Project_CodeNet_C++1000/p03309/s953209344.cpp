#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
  int n;
  cin >> n;
  vector<ll>ar(n);
  for(int i = 0; i < n; i++){
    ll a;cin>>a;
    ar[i]=a-i-1;
  }
  sort(ar.begin(),ar.end());
  ll ans=0;
  if(n%2)
  {
      ll b=ar[n/2];
      for(int i=0;i<n;i++)
        {ans+=abs(ar[i]-b);}
    cout<<ans<<endl;
  }
  else
  {
     ll b1=ar[n/2-1];
     ll b2=ar[n/2];
     //cout<<b1<<" "<<b2<<endl;
     ll ans1=0;
     for(int i=0;i<n;i++)
        {ans+=abs(ar[i]-b1);ans1=abs(ar[i]-b2);}
    cout<<max(ans,ans1)<<endl;
  }
}
    
    

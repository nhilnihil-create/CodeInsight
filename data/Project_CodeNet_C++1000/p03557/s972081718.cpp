#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  cin>>n;
  ll vec[n],vecb[n],vecc[n];
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  for(int i=0;i<n;i++){
    cin>>vecb[i];
  }
  for(int i=0;i<n;i++){
    cin>>vecc[i];
  }
  sort(vec,vec+n);sort(vecb,vecb+n);sort(vecc,vecc+n);
  ll ans=0;
  for(int i=0;i<n;i++){
    ll s=lower_bound(vec,vec+n,vecb[i])-vec;
    s*=n-(lower_bound(vecc,vecc+n,vecb[i]+1)-vecc);
    ans+=s;
  }
  cout<<ans<<endl;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  cin>>n;
  ll vec[n];
  ll powers[31];
  map<ll,int> ma;
  powers[0]=2;
  for(int i=1;i<31;i++){
    powers[i]=2*powers[i-1];
  }
  for(int i=0;i<n;i++){
    cin>>vec[i];
    ma[vec[i]]++;
  }
  sort(vec,vec+n);
  reverse(vec,vec+n);
  int ans=0;
  ll x;
  int y;
  for(int i=0;i<n;i++){
    if(ma[vec[i]]>0){
      for(int j=30;j>=0;j--){
        x=powers[j]-vec[i];
        if(x<=0){
          break;
        }
        if(x==vec[i]){
          ans+=ma[vec[i]]/2;
          ma[vec[i]]%=2;
          continue;
        }
        ans+=min(ma[vec[i]],ma[x]);
        y=min(ma[vec[i]],ma[x]);
        ma[vec[i]]-=y;
        ma[x]-=y;
      }
    }
  }
  cout<<ans<<endl;      
}
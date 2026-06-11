#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  if(n>=m){
    cout<<0<<endl;
    return 0;
  }
  int vec[m];
  for(int i=0;i<m;i++){
    cin>>vec[i];
  }
  sort(vec,vec+m);
  int vecb[m-1];
  for(int i=0;i<m-1;i++){
    vecb[i]=vec[i+1]-vec[i];
  }
  sort(vecb,vecb+m-1);
  reverse(vecb,vecb+m-1);
  int ans=vec[m-1]-vec[0];
  for(int i=0;i<n-1;i++){
    ans-=vecb[i];
  }
  cout<<ans<<endl;
}
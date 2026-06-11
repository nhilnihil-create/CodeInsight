#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  int m,k;
  cin>>m>>k;
  if(k==0){
	rep(i,1<<m)
      cout<<i<<" "<<i<<endl;
    return 0;
  }
  if(k==1&&m==1){
    cout<<-1<<endl;
    return 0;
  }
  if(k>=1<<m){
    cout<<-1<<endl;
    return 0;
  }
  cout<<k<<endl;
  rep(i,1<<m){
    if(i==k)continue;
	cout<<i<<endl;
  }
  cout<<k<<endl;
  for(int i=(1<<m)-1;i>=0;i--){
	if(i==k)continue;
	cout<<i<<endl;
  }
}

#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

int main(){
  int n,m,X,Y;
  cin>>n>>m>>X>>Y;
  int x[n],y[m];
  rep(i,n)
    cin>>x[i];
  rep(i,m)
    cin>>y[i];
  bool flag=false;
  for(int i=X+1;i<=Y;i++){
    bool flag1=false,flag2=false;
    rep(j,n){
      if(x[j]>=i)
	break;
      if(j==n-1){
	flag1=true;
	//cout<<"Z=="<<i<<endl;
	//	cout<<"n-1=="<<n-1<<endl;
	//cout<<"j=="<<j<<endl;
      }}
    rep(k,m){
      if(y[k]<i)
	break;
      if(k==m-1){
	flag2=true;
	//cout<<k<<endl;
      }}
    if(flag1&&flag2)
      flag=true;
  }
  
  if(flag)
    cout<<"No War"<<endl;
  else
    cout<<"War"<<endl;
  
  


  return 0;
}

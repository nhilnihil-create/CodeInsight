#include<bits/stdc++.h>
#define int long long 
#define rao(i,n) for(int i=0;i<n;i++)
using namespace std;
signed main(){
  	int n,a,b,c[100000],d[1000000],z=0;
  cin>>n>>a>>b;
  for(int i=0;i<n;i++){
    cin>>c[i]>>d[i];
  }
  for(int i=0;i<n;i++){
	if(a<=c[i] && b<=d[i]){
      z++;
    }
  }
  cout<<z<<"\n";
}
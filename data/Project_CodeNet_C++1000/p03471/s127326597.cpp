#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,y;cin>>n>>y;
  int k;
  for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++){
    	if(i+j>n)continue;
      k = n-(i+j);
      if(1000*i+5000*j+10000*k == y){cout<<k<<' '<<j<<' '<<i;return 0;}
      
    }
  cout<<-1<<' '<<-1<<' '<<-1;
}
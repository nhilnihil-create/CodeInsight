#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<unordered_map>
#define ll long long 
#define dd double
using namespace std;
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m;
  cin>>n>>m;
  int l[m],r[m];
  int i;
  for(i=0;i<m;i++){
  	cin>>l[i]>>r[i];
  }
  
  int x=l[0];
  int y=r[0];
  for(i=0;i<m;i++){
  	x=max(l[i],x);
  	y=min(r[i],y);
  	
  }
  
  
  int ans=y-x+1;
  if(ans<0){
  	cout<<"0"<<endl;
  }
  else if(ans>n){
  	cout<<n<<endl;
  }
  
  else{
  	cout<<ans<<endl;
  }
  
  return 0;
}
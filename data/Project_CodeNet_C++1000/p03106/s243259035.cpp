#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
  int a,b,k;
  cin>>a>>b>>k;
  
  int ch=min(a,b);
  int count =0;
  int ans=0;
  
  for(int i=min(a,b);0<i;i--){
  	if(a%i==0&&b%i==0){
      	ans=i;
      	count++;
      
    }
    
    if(count==k)break;
  }
  
  cout<<ans<<endl;
  
	
}
    
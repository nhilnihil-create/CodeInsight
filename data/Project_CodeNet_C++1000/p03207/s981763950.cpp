#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int n;
  	cin>>n;
  
  	int p[n];
  	rep(i,n){cin>>p[i];}
  
  	int ans=0;
  	int max=0;
  	  	
  	for(int i=0;i<n;i++){
    	if(p[i]>max){
        	ans+=max;
          	max=p[i];
        }
      
      	else{
        	ans +=p[i];
        }
    }
  
  cout<<ans+(max/2)<<endl;
}
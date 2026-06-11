#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int a,b;
  	cin>>a>>b;
  
  	int ans=0;
  
  	if(a>=b){
    	ans+=a;
      	a--;
    }
  
  	else{
    	ans+=b;
      	b--;
    }
  
    	if(a>=b){
    	ans+=a;
      	a--;
    }
  
  	else{
    	ans+=b;
      	b--;
    }
  
  cout<<ans<<endl;
  
}
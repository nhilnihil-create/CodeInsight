#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int a[5];
  	
  
  	rep(i,5){
    	cin>>a[i];
    }
  
	int ans =0;
  	int lo=a[0];
  
  	for(int j=1;j<5;j++){
    	if(lo%10>a[j]%10&&a[j]%10!=0){
          	ans +=lo+(10-lo%10);
          	lo=a[j];
        }
      
      	else if(a[j]%10==0){
        	ans+=a[j];
        }
      
      	else{
        	ans+=a[j]+10-(a[j]%10);
        }
    }
  
  cout<<ans+lo<<endl;
  
  
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int n;
  	cin>>n;
  
  vector<string> s(n);
  vector<long double> x(n);
  
  rep(i,n){
  	cin>>x[i]>>s[i];
  }
  
  long double ans=0;
  
  rep(j,n){
  	if(s[j]=="JPY"){
     	ans+=x[j]; 
    }
    
    else{
    	ans+=x[j]*380000;
    }
   }
  
  cout<<ans<<endl;
}
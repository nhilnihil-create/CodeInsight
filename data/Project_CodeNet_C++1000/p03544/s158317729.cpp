#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<=(n);i++)
typedef long long ll;

int main() {
  	ll n;
	cin>>n;
  
  	ll p[100];
  
	ll ans=0;
  	p[0]=2;
  	p[1]=1;
  
  	for(int i=2;i<=n;i++){
    	p[i]=p[i-2]+p[i-1];
    }
  cout<<p[n]<<endl;

}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int a,b;
  	cin>>a>>b;
  
  if(a<=5){
  	cout<<0<<endl;
  }
  
  else if(a>=6&&a<=12){
  	cout<<b/2<<endl;
  }
  
  else {
  	cout<<b<<endl;
  }
}
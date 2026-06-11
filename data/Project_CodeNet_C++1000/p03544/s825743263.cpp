#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
  long long a=2,b=1;
  if(n==0)cout<<a;
  if(n==1)cout<<b;
  else{
    long long c;
  	for(int i=2;i<=n;i++){
    	c = b;
      b  = a+b;
      a  = c;
    }
    cout<<b;
  }
}
#include<bits/stdc++.h>
using namespace std;
int main(){
	int d,n;
  cin>>d>>n;
  if(d==0 && n!=100)cout<<n;
  else if(d==0 && n==100) cout<<101;
  else if(d==1 && n!=100)cout<<100*n;
  else if(d==1 && n==100)cout<<100*101;
  else if(d==2 && n!=100)cout<<100*100*n;
  else cout<<100*100*101;
}
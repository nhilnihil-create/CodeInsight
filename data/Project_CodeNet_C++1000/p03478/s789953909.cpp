#include<bits/stdc++.h>
using namespace std;
int checksum(int n){
	int sumi=0;
  while(n!=0){
  	sumi+=n%10;
    n/=10;
  }
  return sumi;
}
int main(){
	int n,a,b;cin>>n>>a>>b;
  int sum=0;
  for(int i=1;i<=n;i++){
  	if(checksum(i)>=a && checksum(i)<=b)sum+=i;
  }
  cout<<sum;
}
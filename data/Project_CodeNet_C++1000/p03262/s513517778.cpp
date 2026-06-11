#include<bits/stdc++.h>
using namespace std;
int mgcd(int a,int b){
	if(b==0)return a;
  else return mgcd(b,a%b);
}
int main(){
	int n,x;cin>>n>>x;
  vector<int >nos(n,0);
  for(int i=0,a;i<n;i++){cin>>a;nos[i]=abs(x-a);}
  int gcd = nos[0];
  for(int i=1;i<n;i++){
  	gcd = mgcd(gcd,nos[i]);
  }
  cout<<gcd;
}
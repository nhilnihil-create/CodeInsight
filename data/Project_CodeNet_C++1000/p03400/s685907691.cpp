#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,d,x;cin>>n>>d>>x;
  int total=0;
  for(int i=0,a;i<n;i++){
  	cin>>a;
    for(int j=0;(j*a+1)<=d;j++)total+=1;
  }
  cout<<total+x;
}
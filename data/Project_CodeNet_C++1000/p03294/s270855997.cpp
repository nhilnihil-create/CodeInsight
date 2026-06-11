#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
  cin>>n;
  
  int maxi=0;
  for(int i=0,a;i<n;i++){cin>>a;maxi+=(a-1);}
  cout<<maxi;
}
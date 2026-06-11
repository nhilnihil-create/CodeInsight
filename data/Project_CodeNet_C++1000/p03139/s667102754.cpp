#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
  
  int n,a,b;
  cin>>n>>a>>b;
  
  cout<<min(a,b)<< " "<<max(0LL,a+b-n);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int n;
  	cin>>n;
  
  vector<int> c(50);
  vector<int> v(50);
  
  rep(i,n)cin>>c[i];
  rep(j,n)cin>>v[j];
  
  int vc=0;
  
  rep(k,n){
  	if(c[k]>v[k]){
    	vc+=c[k]-v[k];
    }
  }
  
  cout<<vc<<endl;
  
}
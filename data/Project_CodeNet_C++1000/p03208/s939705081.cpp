#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int n,k;
  	cin>>n>>k;
  
  	vector <int> p(n);
  	rep(j,n){cin>>p[j];}
  
  	sort(p.begin(), p.end());
  
  	ll ans = 10000000000;
  
  	for(int i=0;i<n-k+1;i++){
    	ll tmp=p[i+k-1]-p[i];
        	ans=min(ans,tmp);
        }
    
      cout<<ans<<endl;
    }
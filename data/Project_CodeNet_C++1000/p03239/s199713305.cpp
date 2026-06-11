#include <bits/stdc++.h>
using namespace std;
#define ALL(obj) (obj).begin(),(obj).end()
#define SORTD(s) sort((s).rbegin(),(s).rend())
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
#define PI 3.14159265358979323846264338327950L
const int mod=1000000007,MAX=200005,INF=1<<30;

int main() {
	int n,t;
  	cin>>n>>t;
  
  	int c[1010];
  	int p[1010];
  	
  	rep(i,n){
    	cin>>c[i]>>p[i];
    }
  	int ans=989999;
  
  for(int i=0;i<n;i++){
  	if(p[i]>t){
    	continue;
    }
    
    else{
    	if(c[i]<ans){
        	ans=c[i];
        }
    }
  }
  
  if(ans==989999){
  	cout<<"TLE"<<endl;
  }
  
  else{
  	cout<<ans<<endl;
  }

}
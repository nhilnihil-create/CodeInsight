#include <bits/stdc++.h>
using namespace std;
#define ALL(obj) (obj).begin(),(obj).end()
#define SORTD(s) sort((s).rbegin(),(s).rend())
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
#define PI 3.14159265358979323846264338327950L


int main() {
	int n,m,x,y;
  	cin>>n>>m>>x>>y;
  
  	int p[n],q[m];
  	int ap=-100;
  	int aq=100;
  
	rep(i,n){
      cin>>p[i];
      if(ap<p[i]){
      	ap=p[i];
      }
    }
  
  	rep(j,m){
    	cin>>q[j];
      if(aq>q[j]){
      	aq=q[j];
      }
    }
  
  

  
  if(ap<aq&&x<aq&&aq<=y){
  	cout<<"No War"<<endl;
  }
  
  else{
  	cout<<"War"<<endl;
  }
  	



}
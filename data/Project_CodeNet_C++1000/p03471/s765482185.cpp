#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i< (n) ; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main(){
 int n,m,res[3]={-1,-1,-1};
  cin >> n >> m;
  m=m/1000;
  rep(i,n+1){
  	rep(j,n-i+1){
  		if(m==9*i+4*j+n)	{
 	      res[0]=i;
          res[1]=j;
          res[2]=n-i-j;
        }
      
  	}
  }
  
  cout << res[0] << " " << res[1] << " " << res[2] <<endl;
    return 0;
}

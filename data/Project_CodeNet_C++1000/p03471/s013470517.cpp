#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
#define ALL(obj) (obj).begin(), (obj).end();


int main() {
	int n,y;
  	cin>>n>>y;
  	
  bool ok=false;
  int a,b,c;
  	
  
  	for(int i=0;i<=n;i++){
    	for(int j=0;j<=n;j++){
        	int k=n-i-j;
          if(10000*i+5000*j+1000*k==y&&k>=0){
            a=i;
            b=j;
            c=k;
          	ok=true;
            break;
          }
          
        }
    }
  
  if(ok)cout<<a<<" "<<b<<" "<<c<<endl;
  else cout<<-1<<" "<<-1<<" "<<-1<<endl;
}

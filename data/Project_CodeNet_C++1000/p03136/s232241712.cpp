#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int n;
  	cin>>n;
  
  int sum=0;
  int ma=0;
  
  int l[n];
  rep(i,n){cin>>l[i];
           sum+=l[i];
          if(ma<=l[i]){
          	ma=l[i];
          }
       }
  
  if(ma<sum-ma){
  	cout<<"Yes"<<endl;
  }
 
  else{
  	cout<<"No"<<endl;
  }
  
  
  
}
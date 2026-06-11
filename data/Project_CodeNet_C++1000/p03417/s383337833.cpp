#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

int main(){
ll n,m;
cin>>n>>m;
if(n==1&&m==1){
  cout<<1<<endl;
  return 0;
}
else if(n==1){
  cout<<m-2<<endl;
  return 0;
}
else if(m==1){
  cout<<n-2<<endl;
  return 0;
}


cout<<(n-2)*(m-2)<<endl;







return 0;
}

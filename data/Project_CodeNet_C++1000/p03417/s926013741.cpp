#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;


int main(){
  
  ll m,n; cin>>m>>n;
  if(m==1&&n==1){
    cout<<1<<endl;
  }
  else if(m==1||n==1){
    cout<<n+m-1-2<<endl;
  }
  else cout << m*n-(2*(m+n)-4)<<endl;
  
  
}

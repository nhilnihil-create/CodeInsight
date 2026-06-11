#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  ll n,m;
  cin>>n>>m;
  if(n!=1 && m!=1){
    cout<<(n-2)*(m-2)<<endl;
  }
  else if(n==1 && m==1){
    cout<<1<<endl;
  }
  else{
    cout<<n*m-2<<endl;
  }
}
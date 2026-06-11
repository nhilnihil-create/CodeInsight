#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int a,b,k;
  cin>>a>>b>>k;
  int d=a+k-1;
  int e=b-k+1;
  if(d>=e){
    rep(i,a,b+1) cout<<i<<endl;
  }
  else{
    rep(i,a,d+1) cout<<i<<endl;
    rep(i,e,b+1) cout<<i<<endl;
  }
}
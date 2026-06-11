#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n,m;
  cin>>n>>m;
  int c[m];
  rep(i,0,m) c[i]=0;
  rep(i,0,n){
    int k;
    cin>>k;
    rep(j,0,k){
      int a;
      cin>>a;
      c[a-1]++;
    }
  }
  int d=0;
  rep(i,0,m){
    if(c[i]==n) d++;
  }
  cout<<d<<endl;
}
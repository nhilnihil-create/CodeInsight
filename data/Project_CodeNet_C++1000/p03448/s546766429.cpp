#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int a,b,c,x;
  cin>>a>>b>>c>>x;
  int d=0;
  rep(i,0,a+1){
    rep(j,0,b+1){
      rep(k,0,c+1){
        if(500*i+100*j+50*k==x) d++;
      }
    }
  }
  cout<<d<<endl;
}
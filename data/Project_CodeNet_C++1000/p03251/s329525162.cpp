#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;
typedef pair<ll,int> P;


int main(){
  int n,m,x,y;
  cin>>n>>m>>x>>y;
  int a=-100;
  rep(i,0,n){
    int cur;
    cin>>cur;
    a=max(a,cur);
  }
  int b=100;
  rep(i,0,m){
    int cur;
    cin>>cur;
    b=min(b,cur);
  }
  if(a>=b) cout<<"War"<<endl;
  else if(b<=x || a>=y) cout<<"War"<<endl;
  else cout<<"No War"<<endl;
}
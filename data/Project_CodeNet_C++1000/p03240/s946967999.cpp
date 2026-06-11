#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

struct info{
  int x;
  int y;
  ll h;
};

int main(){
  int n;
  cin>>n;
  info a[n];
  int cur;
  rep(i,0,n){
    int x,y;
    ll h;
    cin>>x>>y>>h;
    info b={x,y,h};
    a[i]=b;
    if(h>0) cur=i;
  }
  rep(i,0,101){
    rep(j,0,101){
      bool p=true;
      ll h=a[cur].h+abs(i-a[cur].x)+abs(j-a[cur].y);
      rep(k,0,n){
        if(max(h-abs(i-a[k].x)-abs(j-a[k].y),(ll)0)!=a[k].h){
          p=false;
        }
      }
      if(p){
        cout<<i<<" "<<j<<" "<<h<<endl;
      }
    }
  }
}
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const ll INF=1e18;

int main() {
  ll n,m,k;
  cin >>n>>m;
  rep(i,n){
    rep(j,n-i){
      k=n-i-j;
      if(m==i*10000+j*5000+k*1000){
        cout << i<<" "<< j<<" "<<k<<endl;
        return 0;
      }
    }
  }
  cout <<"-1 -1 -1"<<endl;
}
#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;

ll d[3]={3,5,7};
int ans=0;

bool check(ll g){
  bool e[3]={0,0,0};
  string k=to_string(g);
  int p=k.size();
  rep(r,p){
    if(k[r]=='3')e[0]=1;
    if(k[r]=='5')e[1]=1;
    if(k[r]=='7')e[2]=1;
  }
  if(e[0]==1 && e[1]==1 && e[2]==1){return 1;}else{return 0;}
}

void f(ll g,ll q){
  if(g>q)return;
  if(check(g))ans++;
  rep(ii,3){
    f(g*10+d[ii],q);
  }
}

int main(){
  ll x;
  cin >> x;
    f(0,x);
  cout << ans << endl;
}
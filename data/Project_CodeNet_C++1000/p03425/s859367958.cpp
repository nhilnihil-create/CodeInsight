#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;



int main(){
  int n;
  cin >>n;
  ll a[5]={};
  rep(i,n){
    string g;
    cin  >>g;
    if(g[0]=='M'){a[0]++;}
    if(g[0]=='A'){a[1]++;}
    if(g[0]=='R'){a[2]++;}
    if(g[0]=='C'){a[3]++;}
    if(g[0]=='H'){a[4]++;}
  }
  ll ans=0;
  rep(i,5){
    for(int r=i+1;r<5;r++){
      for(int t=r+1;t<5;t++){
        ans+=a[i]*a[r]*a[t];
      }
    }
  }
  cout << ans <<endl;
}
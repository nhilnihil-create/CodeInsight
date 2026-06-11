#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int P [10]={0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,2};
int Q [10]={1 ,1 ,1 ,2 ,2 ,3 ,2 ,2 ,3 ,3};
int R [10]={2 ,3 ,4 ,3 ,4 ,4 ,3 ,4 ,4 ,4};
ll d[5];
ll m,a,r,c,h;

int main(){
  int n; cin >>n;
  rep(i,n){
    string s; cin >>s;
    if(s[0]=='M') m++;
    if(s[0]=='A') a++;
    if(s[0]=='R') r++;
    if(s[0]=='C') c++;
    if(s[0]=='H') h++;
  }
  d[0]=m,d[1]=a,d[2]=r,d[3]=c,d[4]=h;
  ll ans = 0;
  rep(i,10){
    ans += d[P[i]]*d[Q[i]]*d[R[i]];
  }
  cout << ans << endl;
  return 0;
}
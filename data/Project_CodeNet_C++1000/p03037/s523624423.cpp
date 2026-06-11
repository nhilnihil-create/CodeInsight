#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long int ll;
typedef unsigned long long int ull;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  cin >>n>>m;
  int mi=0,ma=n;
  rep(i,m){
    int s,b;
    cin >>s>>b;
    mi = max(mi,s);
    ma = min(ma,b);
  }
  cout <<max(0,ma-mi+1);
}
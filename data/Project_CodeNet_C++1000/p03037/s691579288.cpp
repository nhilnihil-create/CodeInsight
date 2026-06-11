#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n,m;
  cin >> n >> m;

  int l=0,r=100000;
  rep(i,m){
    int nowl, nowr;
    cin >> nowl >> nowr;

    l = max(l,nowl);
    r = min(r,nowr);
  }
  //cout << l << " " << r << endl;
  cout << max(0,r-l+1);
}
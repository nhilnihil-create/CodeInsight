#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const int INT_INF = 2147483647;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
  int n;
  cin >> n;
  int a[n];
  rep(i,n)cin >> a[i];
  int maxv=-INT_INF;
  int maxi;
  int minv=INT_INF;
  int mini;
  rep(i,n){
    if(chmax(maxv,a[i]))maxi=i+1;
    if(chmin(minv,a[i]))mini=i+1;
  }
  if(minv>=0){
    cout << n-1 << endl;
    rep(i,n-1)cout << i+1 << " " << i+2 << endl;
  }else if(maxv<=0){
    cout << n-1 << endl;
    rep(i,n-1)cout << n-i << " " << n-i-1 << endl;
  }else if(maxv>abs(minv)){
    cout << 2*n-1 << endl;
    rep(i,n)cout << maxi << " " << i+1 << endl;
    rep(i,n-1)cout << i+1 << " " << i+2 << endl;
  }else{
    cout << 2*n-1 << endl;
    rep(i,n)cout << mini << " " << i+1 << endl;
    rep(i,n-1)cout << n-i << " " << n-i-1 << endl;
  }
  return 0;
}

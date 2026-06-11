#include <bits/stdc++.h>
#include <fstream>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}


int main() {
  int a,b,c,X;
  cin >> a >> b >> c >> X;
  int cnt=0;
  rep(i,a+1) rep(j,b+1) rep(k,c+1) {
    if (500*i + 100*j + 50*k == X) cnt++;
  }
  cout << cnt << endl;
} 
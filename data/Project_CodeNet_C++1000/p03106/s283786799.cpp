#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) { a = b; return 1; }
  return 0; }
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) { a = b; return 1; }
  return 0; }

int main(void){
  int a,b,k; cin >> a >> b >> k;
  for(int i = 100; i >= 1; i--){
    if(a%i == 0 && b%i == 0){
      k--;
    }
    if(k == 0){
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}

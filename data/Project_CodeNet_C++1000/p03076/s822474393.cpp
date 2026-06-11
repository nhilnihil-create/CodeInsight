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
  int a[5]; rep(i,5) cin >> a[i];
  int mn = 10,check;
  for(int i = 0; i < 5; i++){
    if(a[i]%10 != 0 && a[i]%10 < mn){
      mn = a[i]%10;
      check = i;
    }
  }
  int sum = 0;
  rep(i,5){
    if(i == check) continue;
    else if(a[i]%10 != 0){
      sum += floor(a[i]/10)*10+10;
    }
    else sum += a[i];
  }
  sum += a[check];
  cout << sum << endl;
  return 0;
}

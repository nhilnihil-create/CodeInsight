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
  ll n; cin >> n;
  ll a[n];
  int check = 0; 
  rep(i,n){
    ll b;
    cin >>b;
    if(b >= 0) a[i] = b;
    else{
      a[i] = -1*b;
      check++;
    }
  }
  sort(a,a+n);
  if(check % 2 == 1){
    a[0] = a[0]*-1;
  }
  ll sum = 0;
  rep(i,n){
    sum += a[i];
  }
  cout << sum << endl;
  return 0;
}

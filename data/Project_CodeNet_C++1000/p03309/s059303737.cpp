#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n+1;i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end())
typedef long long ll;
typedef vector<int> vec;
typedef vector<vector<int>> vv;


int main(){
  int n;
  cin >> n;
  vec a(n);
  rep(i,n) cin >> a[i];
  vec b(n);
  rep(i,n) b[i] = a[i] - i - 1;
  sort(b);
  int med;
  if(n%2 == 0) med = (b[n/2]+b[(n-1)/2])/2;
  else med = b[n/2];
  ll ans = 0;
  rep(i,n){
    ans += abs(a[i] - i - 1 -  med);
  }
  cout << ans << endl;
}
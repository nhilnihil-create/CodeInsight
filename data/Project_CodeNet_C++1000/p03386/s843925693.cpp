#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
using ll = long long;
using namespace std;
int main(){
  int a,b,k;
  cin >> a >> b >> k;
  map<int, int> ans;
  rep(i, k){
    if(i + a <= b) ans[i + a]++;
  }
  for(int i = k - 1; i >= 0; i--){
    if(b - i >= a) ans[b - i]++;
  }
  for(auto a : ans) cout << a.first << endl;
}
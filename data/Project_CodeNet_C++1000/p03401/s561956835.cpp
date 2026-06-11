#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
using ll = long long;
using namespace std;
int main(){
  int n;
  cin >> n;
  vi a(n + 2, 0);
  ll total = 0;
  rep(i, n){
    cin >> a[i + 1];
    total += abs(a[i] - a[i + 1]);
  }
  total += abs(a[n]);
  for(int i = 1; i <= n; i++){
    cout << total + abs(a[i - 1] - a[i + 1]) - abs(a[i] - a[i + 1]) - abs(a[i] - a[i - 1]) << endl;
  }
}
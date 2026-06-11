#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
 int n,x;
 cin >> n >> x;
 vector<int> a(n);
 rep(i,n) cin >> a.at(i);
 int b = x;
 rep(i,n) b-=a.at(i);
 sort(a.begin(),a.end());
 int ans = n + b/a.front();
 cout << ans << endl;
 } 
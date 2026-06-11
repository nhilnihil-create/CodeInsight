#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  string s; cin >> s;
  int n = s.size();
  string t = "";
  rep(i,n) if (s[i]!='x') t+=s[i];
  int m = t.size();
  string u = t;
  reverse(all(u));
  
  if (t!=u) {
    cout << -1 << endl;
    return 0;
  }
  int a[(m+1)/2] = {};
  int idx = 0;

  rep(i,(m+1)/2) {
    int cnt = 0;
    while (s[idx]=='x') cnt++, idx++;
    a[i] = cnt;
    idx++;
  }
  idx = n-1;
  rep(i,(m+1)/2) {
    int cnt = 0;
    while (s[idx]=='x') cnt++, idx--;
    a[i] -= cnt;
    idx--;
  }
  int ans = 0;
  rep(i,(m+1)/2) ans +=  abs(a[i]);
  cout << ans << endl;
  // cout << fixed << setprecision(10);
  
  return 0;
}

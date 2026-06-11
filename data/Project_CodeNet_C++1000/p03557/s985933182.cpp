#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ALL(a)  (a).begin(),(a).end()
 
int main(){
  int n;
  cin >> n;
  vector<int> a(n),b(n),c(n);
  for(int i = 0; i < n; ++i) cin >> a[i];
  for(int i = 0; i < n; ++i) cin >> b[i];
  for(int i = 0; i < n; ++i) cin >> c[i];
  
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  sort(c.begin(),c.end());
  
  ll res = 0;
  for(int i = 0; i < n; ++i){
    res += (lower_bound(ALL(a),b[i]) - a.begin())
           * (c.end() - upper_bound(ALL(c),b[i]));
  }
  cout << res;
}
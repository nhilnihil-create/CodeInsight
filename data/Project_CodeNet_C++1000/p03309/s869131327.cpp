#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
using vs = vector<string>;
using vb = vector<bool>;
using vll = vector<long long>;
using vpii = vector<pair<int,int>>;
using vivi = vector<vector<int>>;
using vbvb = vector<vector<bool>>;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const int mod = 1000000007;
const int inf = 1001001001;

int main(void) {
  int n;
  cin >> n;
  vi a(n);
  ll sum  = 0;
  rep(i,n) {
    cin >> a[i];
    a[i]-=i+1;
    
  }
  sort(ALL(a));
  int p = lower_bound(ALL(a),1)-a.begin();
  int q = a[n/2];
  
  rep(i,n){
    a[i]-=q;
    sum+=abs(a[i]);
  }
  
  cout << abs(sum) << endl;
  
}



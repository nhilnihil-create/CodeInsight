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
  ll n,m;
  cin >> n >> m;
  if(n==1 && m==1){
    cout << 1 << endl;
    return 0;
  }
  if(n==1 || m==1){
    cout << n*m-2 << endl;
    return 0;
  }
  cout << (n*m)-(2*n+2*m - 4) << endl;
}



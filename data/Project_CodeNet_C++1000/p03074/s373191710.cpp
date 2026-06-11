#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;

int main(){
  int n, k;
  string s;
  vector<int> vec;
  cin >> n >> k;
  cin >> s;
  int cnt = 0;
  if(s[0] == '0') vec.push_back(0);
  for(int i = 1; i <= int(s.size()); i++){
    if(s[i-1] != s[i]){
      vec.push_back(cnt+1);
      cnt = 0;
      continue;
    }
    cnt++;
  }
  int t = 0;
  int si = vec.size();
  for(int i = 0;i < 2 * k + 1;i++){
    if(i == si-1){
      cout << n << endl;
      return 0;
    }
    t+=vec[i];
  }
  int ans = t;
  for(int i = 0; i < si - 2*k-2;i+=2){
    t = t - vec[i] - vec[i+1] + vec[i+2*k+1] + vec[i+2*k+2];
    ans = max(t, ans);
  }
  ans = max(ans, t + vec[si-1] - vec[si-1-2*k-1]-vec[si-1-2*k]);
  cout << ans <<endl; 
}
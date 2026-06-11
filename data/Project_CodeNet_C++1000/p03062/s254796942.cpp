#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define rep1(i,n) for(int i=1; i<(int)n; i++)
#define repa(i,a,n) for(int i=(a); i<(int)(n); i++)
#define all(vec) vec.begin(),vec.end()
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using psi = pair<string, int>;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};
const int mod = 1e9+7;
int gcd(int a, int b){if(a%b == 0){return(b);}else{return(gcd(b, a%b));}}
int lcm(int a, int b){return a / gcd(a, b)*b;}

int N, M, K, H, W, L, R, X;
//string S, T;

signed main(){
  cin >> N;
  vi a(N);
  int asum = 0;
  int mn = 1e15;
  int mnp, cnt = 0;
  bool a0 = false;
  rep(i,N){
    cin >> a[i];
    if(a[i] == 0){a0 = true; continue;}
    if( a[i] < 0) cnt++;
    asum += abs(a[i]);
    if(abs(a[i])<mn){
      mn = abs(a[i]);
      mnp = i;
    }
  }
  if(a0 || cnt%2 == 0) cout << asum << endl;
  else cout << asum - mn*2 << endl;
  return 0;
}

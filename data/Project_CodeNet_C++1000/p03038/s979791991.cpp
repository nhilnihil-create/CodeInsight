#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define rep1(i,n) for(int i=1; i<(int)n; i++)
#define repa(i,a,n) for(int i=(a); i<(int)(n); i++)
#define all(vec) vec.begin(),vec.end()
#define COUT(x) cout<<(x)<<endl
#define YES(x) cout<<(x?"YES":"NO")<<endl
#define Yes(x) cout<<(x?"Yes":"No")<<endl
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
//cout << fixed << setprecision(15);
int N, M, K, H, W, L, R, X;
string S, T;

signed main(){
  cin >> N >> M;
  vi A(N);
  rep(i,N) cin >> A[i];
  vvi B(M,vi(2));
  rep(i,M) cin >> B[i][1] >> B[i][0];
  sort(all(A));
  sort(all(B));
  reverse(all(B));
  
  int a = 0;
  rep(i,M){
    while (B[i][1]>0){
      if(B[i][0] > A[a]){
        A[a] = B[i][0];
        B[i][1]--;
        a++;
      }else{
        break;
      }
    }
  }
  int ans = 0;
  rep(i,N) ans += A[i];
  
  COUT(ans);
  return 0;

}
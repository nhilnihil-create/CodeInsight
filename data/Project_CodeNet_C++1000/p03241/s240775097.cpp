#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(long long i=0; i<(int)n; i++)
#define rep2(i,a,n) for(long long i=(a); i<(int)(n); i++)
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
int lcm(int a, int b){return a * b / gcd(a, b);}

int N, M, K, H, W, L, R, X;
string S, T;
signed main(){
  cin >> N >> M;
  vi yaku;
  for(int i = 1; i*i <= M; i++){ 
    if(M%i==0){
      yaku.push_back(i);
      yaku.push_back(M/i);
    }
  }
  sort(all(yaku), greater<int>());
  rep(i,yaku.size()){
    if(M/yaku[i]>=N){
      cout << yaku[i] << endl;
      break;
    }
  }
  return 0;
}

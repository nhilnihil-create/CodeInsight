#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define rep2(i,a,n) for(int i=(a); i<(int)(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using vll = vector<ll>;
using pii = pair<int, int>;
using psi = pair<string, int>;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};
//const ll mod = 1e9+7;
int gcd(int a, int b){if(a<b) swap(a,b); if (a%b == 0){return(b);}else{return(gcd(b, a%b));}}
int lcm(int a, int b){return a * b / gcd(a, b);}

ll N, M, K, H, W, L, R;

int main(){
  cin >> N;
  vi X(N), Y(N);
  rep(i,N){
    cin >> X[i];
    Y[i]=X[i];
  }
  sort(all(Y));
  int m = Y[N/2-1], n = Y[N/2];
  
  rep(i,N){
    if(X[i]<=m) cout << n << endl;
    else cout << m << endl;
  }
  return 0;
}
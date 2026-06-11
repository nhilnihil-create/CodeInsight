#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
// Euclidean Algorithm
int gcd(int a, int b){if (a%b == 0){return(b);}else{return(gcd(b, a%b));}}
int lcm(int a, int b){return a * b / gcd(a, b);}

int main(){
  int A, B, C, X; cin >> A >> B >> C >> X;
  int ans = 0;
  rep(i,A+1){
    rep(j,B+1){
      rep(k,C+1){
        if( X == 500*i + 100*j + 50*k) ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
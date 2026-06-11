#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0; i<(int)n; i++)
#define rep2(i,a,n) for(long long i=(a); i<(int)(n); i++)
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
const ll mod = 1e9+7;
int gcd(int a, int b){if(a%b == 0){return(b);}else{return(gcd(b, a%b));}}
int lcm(int a, int b){return a * b / gcd(a, b);}

int N, M, K, H, W, L, R, X;
string S, T;

int main(){
  cin >> S;
  int cnt = 0;
  while ((int)S.size() > 1){
    char s = S[0];
    char t = S[S.size()-1];
    if( s == t ){
      S.pop_back();
      S.erase(0,1);
    }else if(s!=t && s == 'x'){
      S.erase(0,1);
      cnt++;
    }else if(s!=t && t == 'x'){
      S.pop_back();
      cnt++;
    }else{
      cout << -1 << endl;
      return 0;
    }
//    cout << S << endl;
  }
  if(S.size() <= 1 )  cout << cnt << endl;
  else cout << -1 << endl;
  return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define P pair<int,int>
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

vint X;
int n,k;

int Count(int a){
  int res = 0;
  for(auto p:X){
    if((p & a) == a){
      res++;
    }
  }
  return res;
}

signed main(){
  cin >> n >> k;
  vint A(n);
  rep(i,0,n) cin >> A[i];
  rep(i,0,n){
    int tmp = 0;
    rep(j,i,n){
      tmp += A[j];
      X.push_back(tmp);
    }
  }
  // rep(i,0,X.size()) cout << X[i] << endl;
  int ans = 0;
  for(int i = 40;i >= 0;i--){
    int key = 1LL<<i;
    if(Count(ans|key) >= k){
      ans |= key;
    }
  }
  cout << ans << endl;
}
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
#define P = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

bool isprime(int v) {
    if (v == 1) return false;
    for (int i = 2; 1LL * i*i <= v; i++) if (v%i == 0) return false;
    return true;
}

signed main(){
  int n;
  cin >> n;
  vvint v(5,vint(0));
  rep(i,1,55555) if(isprime(i)) v[i % 5].push_back(i);

  rep(i,0,n){
    cout << v[1][i] << " ";
  }
}
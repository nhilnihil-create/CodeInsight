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

signed main(){
  int x,y,z,k;
  cin >> x >> y >> z >> k;
  vint A(x);
  vint B(y);
  vint C(z);
  rep(i,0,x) cin >> A[i];
  rep(i,0,y) cin >> B[i];
  rep(i,0,z) cin >> C[i];
  sort(A.rbegin(),A.rend());
  sort(B.rbegin(),B.rend());
  sort(C.rbegin(),C.rend());
  vint ABC;
  rep(a,0,x){
    rep(b,0,y){
      if((a+1)*(b+1) > k) break;
      rep(c,0,z){
        if((a+1)*(b+1)*(c+1) > k) break;
        ABC.push_back(A[a] + B[b] + C[c]);
      }
    }
  }
  sort(ABC.rbegin(),ABC.rend());
  rep(i,0,min(k,x*y*z)){
    cout << ABC[i] << endl;
  }
}

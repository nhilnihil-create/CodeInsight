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
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  sort(C.begin(),C.end());
  vint AB;
  rep(i,0,x){
    rep(j,0,y){
      AB.push_back(A[i]+B[j]);
    }
  }
  sort(AB.rbegin(),AB.rend());
  vint ABC;
  rep(i,0,min(k,x*y)){
    rep(j,0,z){
      ABC.push_back(AB[i]+C[j]);
    }
  }
  sort(ABC.begin(),ABC.end());
  reverse(ABC.begin(),ABC.end());
  rep(i,0,min(k,x*y*z)){
    cout << ABC[i] << endl;
  }
}

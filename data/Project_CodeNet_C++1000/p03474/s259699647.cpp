#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
constexpr char ln =  '\n';

const int mx=100010;
const ll mod=1e9+7;

ll powll(ll n,ll k){ ll ret=1; while(k){ if(k&1)ret=ret*n; n=n*n; k>>=1; } return ret; }

int main(){
  int a,b;
  cin >> a >> b;
  string s;
  cin >> s;
  int n=a+b+1;
  rep(i,n){
    if(0<=i && i<a){
      if('0'<=s[i] && s[i]<='9'){
        continue;
      } else {
        cout << "No" << endl; return 0;
      }
    }
    if(i==a){
      if('-'==s[i]){
        continue;
      } else {
        cout << "No" << endl; return 0;
      }
    }
    if(a+1<=i && i<n){
      if('0'<=s[i] && s[i]<='9'){
        continue;
      } else {
        cout << "No" << endl; return 0;
      }
    }
  }
  cout << "Yes" << endl;

//  cout << ans << ln;
  return 0;
}
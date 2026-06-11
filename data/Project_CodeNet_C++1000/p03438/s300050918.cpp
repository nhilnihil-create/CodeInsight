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
constexpr char ln = '\n';

const int mx=100010;
const ll mod=1e9+7;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  rep(i,n){ cin >> a[i]; }
  rep(i,n){ cin >> b[i]; }

  ll cnta=0,cntb=0;
  rep(i,n){
    if(a[i]>b[i]){
      cntb += a[i]-b[i];
    }
    if(a[i]<b[i]){
      if((b[i]-a[i])%2){
        cnta += (b[i]-a[i]+1)/2;
        cntb++;
      } else {
        cnta += (b[i]-a[i])/2;
      }
    }
  }
  if(cnta>=cntb){
    cout << "Yes" << ln;
  } else {
    cout << "No" << ln;
  }
  return 0;
}
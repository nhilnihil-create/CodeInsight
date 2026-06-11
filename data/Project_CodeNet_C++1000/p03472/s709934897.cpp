#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll N, H;
  cin>>N>>H;
  vector<ll> a(N), b(N);
  for(int i=0;i<N;++i) cin>>a[i]>>b[i];
  sort(a.begin(), a.end(), greater<ll>());
  sort(b.begin(), b.end(), greater<ll>());
  ll attack = a[0];
  ll nage = 0;
  ll num = 0;
  bool kati = false;
  for(int i=0;i<N;++i) {
    if(attack<b[i]) {
      nage += b[i];
      num++;
      if(nage>=H) {
        kati = true;
        break;
      }
    }
  }
  if(kati) {
    cout<<num<<endl;
    return 0;
  }
  H -= nage;
  if(H%a[0]==0) {
    cout<<H/a[0]+num<<endl;
  }
  else {
    cout<<H/a[0]+1+num<<endl;
  }
}


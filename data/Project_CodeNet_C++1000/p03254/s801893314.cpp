#include <bits/stdc++.h>
using namespace std;
#define FOR(i,l,n) for(int i=l; i<n; ++i)
#define REP(i,n) FOR(i,0,n)
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using mii = map<int,int>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
using ti3 = tuple<int,int,int>;

int main(){
  ll n,x; cin>>n>>x;
  vi a(n);
  REP(i,n) cin>>a[i];
  sort(a.begin(),a.end());
  ll sum=0;
  REP(i,n-1){
    if(x>=sum+a[i]) sum+=a[i];
    else{
      cout<<i<<endl;
      return 0;
    }
  }
  if(x==sum+a[n-1]) cout<<n<<endl;
  else cout<<n-1<<endl;
}
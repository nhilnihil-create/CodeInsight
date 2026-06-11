#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout <<(#x)<<" is "<<(x)<<endl
#define debug cout <<"hi"<<endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int MOD=1e9+7;
const int INF32=1<<30;
const ll INF64=1LL<<60;

void solve(){
  string s; cin >>s;
  int a=s[0]-'0',b=s[1]-'0',c=s[2]-'0',d=s[3]-'0';
  bool ok1=1,ok2=1;
  if(a>1||(a==1&&b>2)||(!a&&!b)) ok1=0;
  if(c>1||(c==1&&d>2)||(!c&&!d)) ok2=0;
  if(ok1&&ok2) cout <<"AMBIGUOUS";
  else if(ok1) cout <<"MMYY";
  else if(ok2) cout <<"YYMM";
  else cout <<"NA";
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  solve();
return 0;}
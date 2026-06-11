#include <bits/stdc++.h>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;

/*
 for(i=0; i<N; i++)
   cin >> a[i];
*/




int main(void) {
  ll i, j, k;
  string s;
  cin >> s;
  ll K;
  cin >> K;
  
  set<string> st;
  for(i=0; i<s.size(); i++) {
    for(j=1; j<=K; j++) {
      st.insert(s.substr(i, j));
    }
  }
  
  ll t=0;
  auto it=st.begin();
  for(ll _=0; _<K-1; _++, it++);
  pt(*it);
}


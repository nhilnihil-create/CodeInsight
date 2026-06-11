#include <bits/stdc++.h>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MOD=1e9+7;
static const ll MAX=101010;

/*
 for(i=0; i<N; i++)
   cin >> a[i];
*/




int main(void) {
  ll i, j, k;
  
  ll N;
  cin >> N;
  string s;
  cin >> s;
  
  ll cnt[26]={};
  for(i=0; i<N; i++) cnt[s[i]-'a']++;
  
  ll ans=1;
  for(i=0; i<26; i++) moC(ans, *, cnt[i]+1);
  ans--;
  pt(ans);
  
}



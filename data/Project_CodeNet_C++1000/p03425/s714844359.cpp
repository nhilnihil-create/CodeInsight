#include <bits/stdc++.h>
#include <string>
#define ft first
#define sc second
#define pt(sth) cout << sth << "\n"
#define moca(a, s, b) a=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
template<class T>bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;

/*
 for(i=0; i<N; i++)
   cin >> a[i];
*/


int main(void) {
  ll i, j, k;
  
  ll N;
  cin >> N;
  
  map<char, ll> dic{{'M', 1}, {'A', 2}, {'R', 3}, {'C', 4}, {'H', 5}};
  ll cnt[6]={};
  for(i=0; i<N; i++) {
    string s;
    cin >> s;
    cnt[dic[s[0]]]++;
  }
  
  ll ans=0;
  for(i=1; i<=5; i++) {
    for(j=i+1; j<=5; j++) {
      for(k=j+1; k<=5; k++) {
        ans+=cnt[i]*cnt[j]*cnt[k];
      }
    }
  }
  
  pt(ans);
  
}
 
 

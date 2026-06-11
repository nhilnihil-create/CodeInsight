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
  ll i, j, k, l;
  
  ll A, B;
  cin >> A >> B;
  string s[111];
  
  for(i=0; i<50; i++) {
    s[i]=string(100, '.');
    s[i+50]=string(100, '#');
  }
  A--; B--; //初期配置の段階で白黒一つずつ連結成分が出来ているため
  
  ll h=0, w=0;
  for(i=0; i<B; i++, w+=2) {
    if(w==100) {
      h+=2;
      w=0;
    }
    
    s[h][w]='#';
  }
  
  h=99; w=0;
  for(i=0; i<A; i++, w+=2) {
    if(w==100) {
      h-=2;
      w=0;
    }
    
    s[h][w]='.';
  }
  
  pt(100<<" "<<100);
  for(i=0; i<100; i++) pt(s[i]);
  
}



#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)
#define ALL(v) (v).begin(),(v).end()
#define CLR(t,v) memset(t,(v),sizeof(t))
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}
template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}
template<class T>void chmin(T&a,const T&b){if(a>b)a=b;}
template<class T>void chmax(T&a,const T&b){if(a<b)a=b;}


int nextInt() { int x; scanf("%d", &x); return x;}

bool possible(ll A, ll B, ll K) {
  ll s = max(1LL, K/2 - 100);
  ll t = min(K/2 + 100, K);
  ll p = 0;
  for (ll i = s; i <= t; i++) {
    ll x = i;
    ll y = K+1-i;
    if (x >= A) x++;
    if (y >= B) y++;
    chmax(p, x * y);
  }
  return p < A*B;
}


int main2() {
  int Q = nextInt();
  while(Q-->0) {
    ll A = nextInt();
    ll B = nextInt();
    ll lo = 0;
    ll hi = 2 * max(A, B) + 10;
    while (hi - lo > 1) {
      ll mid = (hi + lo) / 2;
      if (possible(A, B, mid)) lo = mid; else hi = mid;
    }
    cout << lo << endl;
  }
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws)
    main2();
  return 0;
}

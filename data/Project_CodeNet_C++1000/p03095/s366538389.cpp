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


const ll MOD = 1e9 + 7;


int main2() {
  int N; cin >> N;
  string S; cin >> S;

  map<int, ll> count;
  REP(i, N) count[ S[i] ]++;
  ll ans = 1;
  for (char ch = 'a'; ch <= 'z'; ch++) {
    ans *= (count[ ch ] + 1);
    ans %= MOD;
  }
  ans = (ans - 1 + MOD) % MOD;
  cout << ans << endl;
  return 0;
}

int main() {

#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}
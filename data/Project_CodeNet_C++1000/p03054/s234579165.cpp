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
ll nextLong() { ll x; scanf("%lld", &x); return x;}

const int MAX_N = 212345;

int main2() {
  int H = nextInt();
  int W = nextInt();
  int N = nextInt();
  int sr = nextInt();
  int sc = nextInt();
  string S, T; cin >> S >> T;

  bool ans = true;
  int r1 = 1, r2 = H;
  int c1 = 1, c2 = W;
  for (int i = N - 1; i >= 0; i--) {
    if (i != N-1) {
      if (T[i] == 'L') c2++;
      if (T[i] == 'R') c1--;
      if (T[i] == 'U') r2++;
      if (T[i] == 'D') r1--;
      if (r1 < 1) r1 = 1;
      if (c1 < 1) c1 = 1;
      if (r2 > H) r2 = H;
      if (c2 > W) c2 = W;
    }
    if (S[i] == 'L') c1++;
    if (S[i] == 'R') c2--;
    if (S[i] == 'U') r1++;
    if (S[i] == 'D') r2--;
    if (r1 > r2 || c1 > c2) ans = false;
    // cout << r1 << " " << r2 << "  |  " << c1 << " " << c2 << endl;
  }
  if (r1 <= sr && sr <= r2 && c1 <= sc && sc <= c2) {

  } else {
    ans = false;
  }
  cout << (ans ? "YES":"NO") << endl;

  return 0;
}

int main() {

#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}

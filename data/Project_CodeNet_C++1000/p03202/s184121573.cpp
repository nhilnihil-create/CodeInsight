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

int A[MAX_N];
bool possible(const int K, const int N) {

  if (K == 1) {
    for (int i = 1; i < N; i++) {
      if (A[i-1] >= A[i]) return false;
    }
    return true;
  }

  map<int, int> S;
  for (int i = 1; i < N; i++) {
    const int x = A[i-1];
    const int y = A[i];
    if (x >= y) {

      auto it = S.upper_bound(y);
      S.erase(it, S.end());

      int j = y;
      for (; j >= 1; j--) {
        ++S[j];
        if (S[j] == K) {
          S.erase(j);
        } else {
          break;
        }
      }
      if (j == 0) return false;
    }
  }
  return true;
}

int main2() {
  int N = nextInt();
  REP(i, N) A[i] = nextInt();

  int hi = N;
  int lo = 0;
  while (hi - lo > 1) {
    int K = (hi + lo) / 2;
    if (possible(K, N)) hi = K; else lo = K;
  }
  cout << hi << endl;
  return 0;
}

int main() {
#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}
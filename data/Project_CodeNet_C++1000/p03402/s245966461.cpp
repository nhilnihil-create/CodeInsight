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

char t[105][105];

int main2() {
  int A = nextInt();
  int B = nextInt();

  int N = 100;
  REP(i, N) REP(j, N) {
    if (i < N / 2)
      t[i][j] = '.';
    else
      t[i][j] = '#';
  }

  int a = 0, b = 0;
  for (int i = 0; i < N/2; i+=2) {
    for (int j = 0; j < N; j += 2) {
      if (b < B-1) {
        t[i][j] = '#';
        b++;
      }
    }
  }
  for (int i = N/2 + 1; i < N; i +=2) {
    for (int j = 0; j < N; j += 2) {
      if (a < A-1) {
        t[i][j] = '.';
        a++;
      }
    }
  }

  cout << N << " " << N << endl;
  REP(i, N) {
    REP(j, N) cout << t[i][j];
    cout << endl;
  }
  return 0;
}

int main() {

#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}
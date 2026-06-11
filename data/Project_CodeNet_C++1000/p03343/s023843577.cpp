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

const int MAX_N = 2010;
int A[MAX_N];
int cannot[MAX_N];

int main2() {
  int N = nextInt();
  int K = nextInt();
  int Q = nextInt();

  REP(i, N) A[i] = nextInt();

  int ans = 1001001001;
  REP(yi, N) {
    CLR(cannot, 0);
    int Y = A[yi]; // Y 未満のものは取れない
    for (int i = 0; i < N; i++) {
      if (A[i] < Y) {
        cannot[i] = 1;
      }
    }
    vector<int> use;
    vector<int> part;
    for (int i = 0; i < N; i++) {
      if (!cannot[i]) {
        part.push_back(A[i]);
      } else {
        sort(ALL(part));
        for (int i = 0; i < (int)part.size()-(K-1); i++) {
          use.push_back(part[i]);
        }
        part.clear();
      }
    }
    if (part.size() > 0) {
      sort(ALL(part));
      for (int i = 0; i < (int)part.size()-(K-1); i++) {
        use.push_back(part[i]);
      }
    }
    sort(ALL(use));
    if ((int)use.size() >= Q) {
      chmin(ans, use[Q-1]-use[0]);
    }
  }

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
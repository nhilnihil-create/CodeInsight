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

const int MAX_N = 112345;
int L[MAX_N];
int R[MAX_N];
ll Lsum[MAX_N];
ll Rsum[MAX_N];

int main2() {
  int N = nextInt();
  REP(i, N) {
    L[i] = nextInt();
    R[i] = nextInt();
  }
  sort(L, L+N); reverse(L, L+N);
  sort(R, R+N);

  Lsum[0] = 0;
  REP(i, N) Lsum[i+1] = Lsum[i] + L[i];
  Rsum[0] = 0;
  REP(i, N) Rsum[i+1] = Rsum[i] + R[i];

  ll ans = 0;
  for (int i = 0; i <= (N+1)/2; i++) {
    for (int j = i-1; j <= i+1; j++) {
      if (0 <= i && i <= N && 0 <= j && j <= N) {
        ll cur = 2*(Lsum[i] - Rsum[j]);
        chmax(ans, cur);
      }
    }
  }
  cout << ans << endl;
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws)
    main2();
  return 0;
}

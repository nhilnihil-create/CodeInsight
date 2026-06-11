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

int get(unsigned int i) {
  i |= (i >>  1);
  i |= (i >>  2);
  i |= (i >>  4);
  i |= (i >>  8);
  i |= (i >> 16);
  return i + 1;
}

int main2() {
  int N = nextInt();
  vector<int> A(N);
  REP(i, N) A[i] = nextInt();
  sort(ALL(A));

  multiset<int> ms;
  REP(i, N) ms.insert(A[i]);

  int ans = 0;
  for (;!ms.empty();) {
    int t = *ms.rbegin();
    ms.erase(--ms.end());
    if (!ms.empty()) {
      int T = get(t);
      int s = T - t;
      auto it = ms.lower_bound(s);
      if (*it == s) {
        ms.erase(it);
        ans++;
      }
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

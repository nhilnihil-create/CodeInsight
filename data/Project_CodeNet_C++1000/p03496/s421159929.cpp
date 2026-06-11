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

int main2() {
  int N = nextInt();
  vector<int> a(N);
  REP(i, N) a[i] = nextInt();

  bool allPositive = true;
  bool allNegative = true;
  REP(i, N) {
    if (a[i] < 0) allPositive = false;
    if (a[i] > 0) allNegative = false;
  }

  vector< pair<int,int> > ops;

  if (allPositive) {
    REP(i, N-1)  ops.push_back( {i, i+1} );
  } else if (allNegative) {
    for (int i = N - 1; i >= 1; i--) ops.push_back( {i, i-1} ); 
  } else {
    int max_abs = 0;
    int max_abs_i = 0;
    REP(i, N) {
      if (abs(a[i]) > max_abs) {
        max_abs = abs(a[i]);
        max_abs_i = i;
      }
    }

    if (a[max_abs_i] > 0) {
      REP(i, N) if (i != max_abs_i) ops.push_back({max_abs_i, i});
      REP(i, N-1)  ops.push_back( {i, i+1} );
    } else {
      REP(i, N) if (i != max_abs_i) ops.push_back({max_abs_i, i});
      for (int i = N - 1; i >= 1; i--) ops.push_back( {i, i-1} ); 
    }

  }


  cout << ops.size() << endl;
  for (auto x : ops) {
    cout << ((x.first) + 1) << " " << ((x.second) + 1) << endl;
  }
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws)
    main2();
  return 0;
}



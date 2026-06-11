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

const int MAX_N = 1024;
int x[MAX_N];
int y[MAX_N];

int main2() {
  int N = nextInt();

  int parity = 0;
  REP(i, N) {
    x[i] = nextInt();
    y[i] = nextInt();
    if ((x[i] + y[i]) & 1) { parity |= 2; } else { parity |= 1; }
  }
  if (parity == 3) {
    cout << -1 << endl;
    return 0;
  }

  bool delta = ((x[0] + y[0]) & 1) == 0;

  vector<int> d;
  if (delta) d.push_back(1);
  for (int i = 0; i < 30; i++) d.push_back(1 << (30-i));
  d.push_back(1);

  printf("%d\n", (int)d.size());
  REP(i, d.size()) { printf(i > 0 ? " " : ""); printf("%d", d[i]); }
  printf("\n");

  REP(q, N) {
    int tx = x[q];
    int ty = y[q];

    string cmd;
    int cur_x = 0, cur_y = 0;
    REP(i, d.size()) {
      if (delta && i == 0) {
        cur_x += d[i];
        cur_y = 0;
        cmd += "R";
        continue;
      }
      int dx = tx - cur_x;
      int dy = ty - cur_y;
      if (dy < dx && dx + dy > 0) { cur_x += d[i]; cmd += "R"; }
      if (dy < dx && dx + dy < 0) { cur_y -= d[i]; cmd += "D"; }
      if (dy > dx && dx + dy > 0) { cur_y += d[i]; cmd += "U"; }
      if (dy > dx && dx + dy < 0) { cur_x -= d[i]; cmd += "L"; }
    }
    printf("%s\n", cmd.c_str());
  }
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws)
    main2();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)
#define ALL(v) (v).begin(),(v).end()
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}
template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}
template<class T>bool chmin(T&a,const T&b){return a>b?(a=b,1):0;}
template<class T>bool chmax(T&a,const T&b){return a<b?(a=b,1):0;}

const int INF = 1001001001;
const int MAX_N = 200000 + 10;
int a[MAX_N];
int dp[1 << 26];

int main2() {
  string s; cin >> s;
  int N = (int)s.size();

  a[0] = 0;
  REP(i, N) {
    a[i+1] = a[i] ^ (1 << (s[i] - 'a'));
  }
  REP(i, 1<<26) dp[i] = INF;
  dp[0] = 0;
  int f = 0;
  for (int i = 1; i <= N; i++) {
    int cur = a[i];
    f = dp[cur] + 1;
    for (int c = 0; c < 26; c++) {
      int next = cur ^ (1 << c);
      chmin(f, (dp[next] + 1));
    }
    chmin(dp[a[i]], f);
  }
  cout << f << endl;
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws) main2();
  return 0;
}


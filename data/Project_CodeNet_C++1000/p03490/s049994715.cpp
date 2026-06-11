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


bool dp[20000];
bool check(vector<int> a, int x) {
  int M = accumulate(ALL(a), 0);
  if (M < abs(x)) return false;
  if ((x+M) % 2 == 1) return false;
  CLR(dp, 0);
  dp[0] = 1;
  for (int ai : a) {
    for (int j = 2*M; j - ai >= 0; j--) {
      if (dp[j-ai]) dp[j] = 1;
    }
  }
  return dp[ (x+M)/2 ];
}


int main2() {
  string s; cin >> s;
  int x, y; cin >> x >> y;

  int i = 0;
  while (i < (int)s.size() && s[i] == 'F') {
    i++;
    x--;
  }

  int dir = 0;
  vector<int> a, b;
  int len = 0;
  for ( ; i < (int)s.size(); i++) {
    if (s[i] == 'T') {
      if (len > 0) { (dir == 0 ? a : b).push_back(len); len = 0; }
      dir = 1 - dir;
    }
    else {
      len++;
    }
  }
  if (len > 0) { (dir == 0 ? a : b).push_back(len); len = 0; }
  
  // cout << s << endl;
  // cout << "a:"; pv(ALL(a));
  // cout << "b:"; pv(ALL(b));

  cout << (check(a, x) && check(b, y) ? "Yes":"No")  << endl;
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws)
    main2();
  return 0;
}

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
  string s; cin >> s;
  int N = s.size();
  s = '_' + s;

  bool possible = true;
  if (s[1] == '0') possible = false;
  if (s[N] == '1') possible = false;
  for (int i = 1; i < N; i++) {
    if (s[i] != s[N-i]) possible = false;
  }
  if (!possible) {
    cout << -1 << endl;
    return 0;
  }

  int one = count(ALL(s), '1');
  for (int i = 1; i + 1 <= one; i++) {
    cout << i << " " << i + 1 << endl;
  }

  int a = 1;
  int b = one + 1;
  for (int i = 1; i < N; i++) {
    if (s[i] == '0') {
      cout << a << " " << b << endl;
      b++;
    } else {
      a++;
    }
  }
  cout << one << " " << b << endl;


  return 0;
}

int main() {

#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}

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

ll nextLong() { ll x; scanf("%lld", &x); return x;}


vector<int> conv(string S) {
  map<char, int> mp;

  vector<int> res(S.size());
  REP(i, S.size()) {

    if (mp.count(S[i]) == 0) {
      int sz = mp.size();
      mp[ S[i] ] = sz;
    }

    res[i] = mp[S[i]];
  }
  return res;

}
int main2() {
  string S, T;
  cin >> S >> T;
  cout << (conv(S) == conv(T) ? "Yes" : "No") << endl;
  return 0;
}

int main() {
    main2();
  return 0;
}
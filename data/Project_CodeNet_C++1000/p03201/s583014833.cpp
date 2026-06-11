#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define SUM(a)  accumulate((a).begin(),(a).end(),0)
#define SORT(a) sort(ALL(a))
#define REV(a) reverse(ALL(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
typedef long long ll;
const int INTINF = 1<<29;
const ll LLINF = 1LL<<61;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
const int DX[8]={ 0, 1, 0,-1, 1, 1,-1,-1};
const int DY[8]={ 1, 0,-1, 0, 1,-1, 1,-1};

int calc_pair(int n){
    int r = 1;
    int k = n;
    while(k>0){
        r<<=1;
        k>>=1;
    }
    return r-n;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  int a;
  int ans = 0;
  cin >> n;
  vector<int> A;
  multiset<int> st;
  REP(i,n){
      cin >> a;
      A.push_back(a);
      st.insert(a);

  }
  SORT(A);
  REV(A);
  REP(i,n){
      a = A[i];
      auto itr = st.find(a);
      if (itr == st.end())continue;
      //dump(st.size());
      st.erase(itr);//ペアを組めなかったとしても、今後使うことはないので決して良い
      //dump(st.size());
      int p = calc_pair(a);
      //cout << a << " " << p << endl;
      itr = st.find(p);
      if (itr == st.end())continue;
      st.erase(itr);
      ans++;
      }
  cout << ans << endl;
}

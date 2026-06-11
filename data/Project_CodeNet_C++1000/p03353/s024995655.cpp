#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  string S;
  cin >> S;
  int K;
  cin >> K;
  set<string> st;
  REP(i,S.size()){
    FOR(j,1,6){
      st.insert(S.substr(i,min(j,(int)S.size()-i)));
    }
  }

  auto itr = st.begin();
  REP(i,K-1){
    itr++;
  }
  cout << *itr << endl;
}
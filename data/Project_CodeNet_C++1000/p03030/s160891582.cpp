#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  set<string> st;
  map<string, vector<pair<int, int> > > mp;
  REP(i, N){
    string S; int P; cin >> S >> P;
    st.insert(S);
    mp[S].push_back({P, i});    
  }
  while(!st.empty()){
    auto itr = st.begin();
    string cur = *itr;
    st.erase(cur);
    vector<pair<int, int> > V = mp[cur];
    sort(V.begin(), V.end(), greater<pair<int, int> >());
    for(auto i : V){
      cout << i.second+1 << endl;
    }
  }
}
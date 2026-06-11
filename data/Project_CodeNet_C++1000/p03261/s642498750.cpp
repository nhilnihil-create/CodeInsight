#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
const ll INF = 10e9;
ll MOD=1000000007;

int main(){
  int n; cin>>n;
  set<string>st;
  vector<string>W(n);
  rep(i,n) cin>>W[i];
  st.insert(W[0]);
  bool jud = true;
  for (int i=1; i<n; i++){
    st.insert(W[i]);
    if (W[i][0]==W[i-1][W[i-1].size()-1]) continue;
    else jud = false;
  }
  if (st.size()!=n) jud = false;
  if (jud) cout << "Yes" << endl;
  else cout << "No" << endl;
}
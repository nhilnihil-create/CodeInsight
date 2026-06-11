#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<string> s(3);
  rep(i,3)cin>>s[i];
  int ans=0;
  rep(i,n){
    set<char> st;
    rep(j,3){
      st.insert(s[j][i]);
    }
    ans+=st.size()-1;
  }
  cout<<ans<<endl;
}
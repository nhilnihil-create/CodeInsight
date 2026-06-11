#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;

int main() {
  string s;
  cin >> s;
  int size=s.size();
  ll ans=0;
  stack<int> st;
  for(int i=0;i<size;i++){
    if(s.at(i)=='B'){
      st.push(i);
    }
  }
  if(st.size()==0){
    cout << 0 << endl;
    return 0;
  }
  int stsize=st.size();
  for(int i=0;i<stsize;i++){
    ans=ans+size-i-1-st.top();
    st.pop();
  }
  cout << ans << endl;
}
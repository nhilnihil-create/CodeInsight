#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  S += ('a' - 1);
  int N = S.size();
  set<char> st;
  for (int i = 0; i < 26; i++){
    st.insert('a' + i);
  }
  string ans = "zz";
  for (int i = 0; i < N; i++){
    if (st.upper_bound(S[i]) != st.end()){
      string T = S.substr(0, i) + *(st.upper_bound(S[i]));
      ans = min(ans, T);
    }
    if (i < N - 1){
      st.erase(S[i]);
    }
  }
  if (ans == "zz"){
    ans = "-1";
  }
  cout << ans << endl;
}
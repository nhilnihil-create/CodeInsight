#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  if(s.size()<26){
    vector<int> a(26,0);
    rep(i,s.size()){
      int pos = s[i] - 'a';
      a[pos] = 1;
    }
    cout << s;
    rep(i,26){
      if(a[i]==0) {
        cout << ((char) ('a'+i)) << endl;
        return 0;
      }
    }
  }
  else{
    set<char> st;
    st.insert(s[25]);
    for(int i = 24; i>=0;i--){
      if(s[i]<s[i+1]){
        rep(j,i) cout << s[j];
        for(auto j:st) {
          if(j>s[i]){
            cout << j << endl;
            return 0;
          }
        }
      }
      st.insert(s[i]);
    }
    cout << -1 << endl;

  }
  
  return 0;
    

}

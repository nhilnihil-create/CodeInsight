#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  rep(i,n){
    set<int> st;
    int tans=0;
    rep(j,i){
      st.insert(s[j]);
    }
    for(int j=i;j<n;j++){
      if(st.count(s[j])) {
        tans++;
        st.erase(s[j]);
      }
    }
    ans = max(ans,tans);
  }
  cout << ans << endl;

  return 0;
    

}

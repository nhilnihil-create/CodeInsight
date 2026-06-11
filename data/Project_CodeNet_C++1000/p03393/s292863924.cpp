#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=200010;
const ll mod=1e9+7;

 
int main(){
  string s;
  cin >> s;
  int n = s.size();
  set<char> st;
  rep(i,n) st.insert(s[i]);

  if(n<=25){
    string ans = s;
    for(char i='a'; i<='z'; i++)if(st.find(i)==st.end()){
      ans += i;
      cout << ans << endl;
      return 0;
    }
  }

  if(s=="zyxwvutsrqponmlkjihgfedcba"){
    cout << -1 << endl; return 0;
  }

  string ans = s;
  next_permutation(ans.begin(),ans.end());
  rep(i,n){
    if(ans[i]!=s[i]){
        ans.erase(i+1,n-1);
      break;
    }
  }
  cout << ans << endl;
  return 0;
}

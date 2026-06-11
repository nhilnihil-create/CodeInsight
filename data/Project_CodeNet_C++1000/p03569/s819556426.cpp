#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }

int main(){
  string s; cin >> s;
  int i = 0, j = (int)s.size()-1;
  int ans = 0;
  while(i < j){
    if(s[i] == s[j]){
      i++;
      j--;
    }else{
      if(s[i] == 'x') i++;
      else if(s[j] == 'x') j--;
      else{
        cout << -1;
        return 0;
      }
      ans++;
    }
  }
  cout << ans;
  cout << "\n";
  return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


string s;
void solve(){
  cin >> s;
  int ans=0;
  for(char c:s){
    if(c=='2')ans++;
  }
  cout << ans << endl;
}

int main(){
  solve();
  return 0;
}

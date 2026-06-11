#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

bool validate(char c){
	if(c == 'A' || c == 'C' || c == 'T' || c == 'G')return true;
	return false;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  string s;
  cin >> s;
  int n = s.size();
  int ans = 0, cnt = 0;
  forn(i, 0, n){
	  if(validate(s[i]))cnt++;
	  else{
		  ans = max(ans, cnt);
		  cnt = 0;
	  }
  }
  ans = max(ans, cnt);
  cout << ans << endl;

}



#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  string S;
  cin >> S;
  int ans = 0,w=0;
  for(int i=0; i<S.size(); i++){
	  if(S[i] == 'W'){
		  ans+= i-w;
		  w++;
	  }
  }
  cout << ans << endl;
}

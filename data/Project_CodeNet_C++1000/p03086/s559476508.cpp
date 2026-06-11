#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string s; cin >> s;

  int ans = 0;
  rep(i,s.size()){
    int tmp = 0;
    if(s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T'){
      tmp++;
      for(int j = i+1;j<s.size();j++){
	if(s[j] == 'A' || s[j] == 'C' || s[j] == 'G' || s[j] == 'T'){
	  tmp++;
	}
	else break;
      }
    }
    ans = max(ans,tmp);
  }

  cout << ans << endl;
  
  return 0;
}

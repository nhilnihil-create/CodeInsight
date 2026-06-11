#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  string S; cin >> S;
  int l=S.size();
  int c=0;
  int ans = 0;
  
  rep(i,l){
      if(S[i]=='A'||S[i]=='C'||S[i]=='G'||S[i]=='T'){
          c++;
          ans = max(ans,c);
      }
      else{
          c = 0;
      }
  }
  cout<<ans<<endl;

	return 0;
}


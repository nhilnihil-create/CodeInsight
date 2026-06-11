#include <bits/stdc++.h>
#define INF 2e9
#define MOD 1000000007
#define MOD9 998244353
#define intMAX 51000;
#define PI 3.14159265359
using namespace std;
typedef long long llong;
typedef long double ldouble;

using Graph = vector<vector<int>>;

int main(){
  string S;
  cin >> S;
  int count = 0;
  int ans = 0;
  for(int i=0; i<S.length(); ++i){
    if(S[i]=='A'||S[i]=='C'||S[i]=='G'||S[i]=='T') ++count;
    else{
      count = 0;
    }
    ans = max(ans, count);
  }
  cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;
typedef vector<string> vs;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  string ans="No";
  for(int i=0; i<=n/4; i++)for(int j=0; j<=n/7; j++){
    if(i*4+j*7==n){
      ans="Yes";
      break;
    }
  }

  cout << ans << endl;

  return 0;
}
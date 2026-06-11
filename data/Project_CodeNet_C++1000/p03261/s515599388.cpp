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
  vs w(n);
  rep(i, n)cin >> w[i];
 
  string ans="Yes";
  rep(i ,n-1){
    int a=(int)w[i].size();
    if(w[i][a-1]!=w[i+1][0]){
      ans="No";
      break;
    }
    for(int j=i+1; j<n; j++){
      if(w[i]==w[j]){
        ans="No";
        break;
      }
    }
  }
 
  cout << ans << endl;

  return 0;
}
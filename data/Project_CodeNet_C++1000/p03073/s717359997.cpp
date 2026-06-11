#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;

int main(){
  string S; cin >> S;
  // 0 start
  int count0 = 0;
  rep(i,(int)S.size()){
    if(i%2 == 0 && S[i] == '1') ++count0;
    else if(i%2 == 1 && S[i] == '0') ++count0;
  }
  // 1 start
  int count1 = 0;
  rep(i,(int)S.size()){
    if(i%2 == 0 && S[i] == '0') ++count1;
    else if(i%2 == 1 && S[i] == '1') ++count1;
  }
  int ans = min(count0, count1);
  cout << ans << endl;
  return 0;
}
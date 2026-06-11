#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  string s;
  cin >> s;
  ll k;
  cin >> k;
  int ans = 1;
  for(ll i=0LL; i<k; i++){
    if((s[i]-'0'!=1)){
      ans = s[i]-'0';
      break;
    }
  }
  cout << ans << endl;
  return 0;
}

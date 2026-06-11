#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  int n;
  cin >> n;
  map<int, int> mp;
  rep(i, n){
    int num;
    cin >> num;
    mp[num]++;
  }
  int ans = 0;
  for(auto p : mp){
    int num = p.first;
    int cnt = p.second;
    if(num > cnt) ans += cnt;
    else ans += cnt-num;
  }
  cout << ans << endl;
  return 0;
}
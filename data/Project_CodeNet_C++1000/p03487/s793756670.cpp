#include <iostream>
#include <map>

using namespace std;

#define repd(i, a, b) for(int i=a; i<b; i++)
#define rep(i, a) repd(i, 0, a)
#define ll long long 

int main(){
  int n;
  cin >> n;
  map<int, int> mp;
  rep(i, n){
    int a;
    cin >> a;
    mp[a]++;
  }
  ll ans = 0;
  for(auto m: mp){
    if(m.first <= m.second){
      ans += m.second - m.first;
    }else{
      ans += m.second;
    }
  }
  cout << ans << endl;
  return 0;
}
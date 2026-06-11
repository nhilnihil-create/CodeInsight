#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i, n)for(int i=0; i<n; i++)

int main(){
  int N;
  cin >> N;
  int a[N];
  rep(i, N)
    cin >> a[i];
  //

  map<int, int> m;
  rep(i, N)
    m[ a[i] ]++;

  long long ans = 0;
  for(auto tmp : m)
    if(tmp.first < tmp.second)
      ans += (tmp.second-tmp.first);
    else if(tmp.second < tmp.first)
      ans += tmp.second;
      
  cout << ans << endl;
  
  return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
  int n,m;
  cin >> n >> m;
  if (n == 1) {
    cout << m << endl;
    return 0;
  }
  map<int,int> div;
  for (int i = 1;i*i <= m;i++){
    if (m%i == 0){
      div[i]++;
      div[m/i]++;
    }
  }
  int ans = 0;
  for (auto q:div){
    //cout << q.first << ":" << q.second << endl;;
    if (q.first <= m/n) ans = max(ans,q.first);
  }
  cout << ans << endl;

}

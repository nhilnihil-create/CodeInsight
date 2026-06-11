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
  int n;
  cin >> n;
  int ans = 0;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  for (int i = 0;i < n; i++){
    for (int j = 0; j < n; j++){
      ans = max(ans,abs(a[i]-a[j]));
    }
  }
  cout << ans << endl;
  return 0; 
}


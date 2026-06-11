#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()
int main() {
  string a;
  cin >> a;
  int sum=0,ans=0,len=a.size();
  rep(i,len){
    if(a.at(i)=='A'||a.at(i)=='T'||a.at(i)=='C'||a.at(i)=='G'){
      sum++;
    }
    else{
      ans = max(ans,sum);
      sum = 0;
    }
  }
  ans = max(ans,sum);
  cout << ans;
}
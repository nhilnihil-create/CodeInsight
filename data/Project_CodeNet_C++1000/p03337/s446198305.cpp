#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  vector<int> ans(3);
  ans.at(0) = a+b;
  ans.at(1) = a-b;
  ans.at(2) = a*b;
  sort(ans.begin(),ans.end());
  cout << ans.at(2) << endl;
}
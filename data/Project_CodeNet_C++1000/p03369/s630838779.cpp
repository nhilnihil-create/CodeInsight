#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
//using ll = long long;
//using P = pair<int,int>;

int main(){
 string s;
  int counts;
  cin >> s;
  rep(i,3) {
  if(s.at(i) == 'o')
    counts++;
  }
  cout << 700 + counts*100 << endl;
}
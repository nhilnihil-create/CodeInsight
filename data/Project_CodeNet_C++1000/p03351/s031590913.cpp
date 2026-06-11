#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

int a, b, c, d;
string res = "No";

int main(){
  cin >> a >> b >> c >> d;
  if(abs(c - a) <= d){
    res = "Yes";
  }
  if(abs(b - a) <= d && abs(c - b) <= d){
    res = "Yes";
  }
  cout << res << endl;
  return 0;
}

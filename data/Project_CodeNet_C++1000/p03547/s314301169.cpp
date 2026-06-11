#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  char x, y;
  cin >> x >> y;

  if (x == y){
    cout << '=' << endl;
  }else if (x < y){
    cout << '<' << endl;
  }else{
    cout << '>' << endl;
  }
}

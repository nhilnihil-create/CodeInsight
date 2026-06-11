#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int d;
  cin >> d;
  int n = 25-d;
  cout << "Christmas" << " ";
  REP(i,n){
    cout << "Eve" << " ";
  }
  cout << endl;
  return 0;
}

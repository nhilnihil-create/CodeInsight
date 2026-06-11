#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  char b;
  cin >> b;

  if(b == 'A') cout << 'T' << endl;
  if(b == 'T') cout << 'A' << endl;
  if(b == 'C') cout << 'G' << endl;
  if(b == 'G') cout << 'C' << endl;

  return 0;
}
#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){

  string s;
  cin >> s;
  int x, pre, back;
  x =  stoi(s);//*10;// +stoi(s[1]);

  pre = x/100;
  back = x - pre*100;
  int ans = 0;
  if(1 <= pre  && pre <= 12) ++ans;
  if(1 <= back && back <= 12) ans += 2;


  if(ans == 3) cout << "AMBIGUOUS" << endl;
  if(ans == 2) cout << "YYMM" << endl;
  if(ans == 1) cout << "MMYY" << endl;
  if(ans == 0) cout << "NA" << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) sort(v.begin(), v.end())
typedef long long ll;
using Graph = vector<vector<int>>;

int main(){
  int s;
  cin >> s;
  int a = s / 100;//1905 → 19
  int b = s % 100;//1905 → 05
  if ((a > 12 || a == 0 )&&( b > 12 || b == 0))
  {
    cout << "NA" << endl;
  }
  else if (a < 13 && a > 0 && b < 13 && b > 0)
  {
    cout << "AMBIGUOUS" << endl;
  }
  else if (a > 12 || a == 0)
  {
    cout << "YYMM" << endl;
  }
  else
  {
    cout << "MMYY" << endl;
  }
}
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
int INF = 100100101;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int mini = INF;
  int tmp,gap;
  for(int i = 0; i <= s.length()-3; i++){
    tmp = stoi(s.substr(i, 3));
    gap = abs(753 - tmp);
    mini = min(gap, mini);
  }
  cout << mini << endl;
}
#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<vector<int>>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
#define INF 1e9
#define All(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;



int main() {
  string s;
  cin >> s;
  sort(All(s));
  if(s=="abc"){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

  return 0;
}

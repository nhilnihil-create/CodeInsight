#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;

int R;

int main() {
  cin >> R;

  if(R < 1200) {
    cout << "ABC" << endl;
  } else if(R < 2800) {
    cout << "ARC" << endl;
  } else {
    cout << "AGC" << endl;
  }
}

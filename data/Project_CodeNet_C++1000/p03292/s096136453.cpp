#include <bits/stdc++.h>
#include <vector>

using namespace std;

int min(int a, int b) {
  return a < b ? a : b;
}

int main(void)
{
    vector<int> a(3);
    for (int i = 0; i < 3; ++i) {
      cin >> a.at(i);
    }

    vector<int> dp(3);
    sort(a.begin(), a.end());
    dp.at(0) = 0;
    for (int i = 1; i < 3; ++i) {
      dp.at(i) = dp.at(i - 1) + abs(a.at(i) - a.at(i - 1));
    }
    cout << dp.at(2) << endl;    
}
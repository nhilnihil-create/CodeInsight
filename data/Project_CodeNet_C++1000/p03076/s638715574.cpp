#include <bits/stdc++.h>
using namespace std;

int main()
{
  // 調理時間
  vector<int> cookingTime(5);
  // 調理時間 + 次の注文ができるまでの時間
  vector<int> spendTime(5);
  // 次の注文ができるまでの時間
  vector<int> waitTime(5);

  for (int i = 0; i < 5; i++)
  {
    cin >> cookingTime.at(i);
    spendTime.at(i) = (cookingTime.at(i) + 9) / 10 * 10;
    waitTime.at(i) = spendTime.at(i) - cookingTime.at(i);
  }

  int sum = accumulate(spendTime.begin(), spendTime.end(), 0);
  int maxWaitTime = *max_element(waitTime.begin(), waitTime.end());

  cout << sum - maxWaitTime << endl;
}

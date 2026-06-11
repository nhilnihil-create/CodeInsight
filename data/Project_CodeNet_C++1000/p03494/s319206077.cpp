#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }

  // 奇数が出るまで繰り返す
  int count = 0;
  bool isOdd = false;
  for (int i = 0;; i++)
  {
    for (int i = 0; i < N; i++)
    {
      if (A.at(i) % 2 == 1)
      {
        isOdd = true;
        break;
      }
      A.at(i) /= 2;
      count++;
    }
    if (isOdd)
    {
      break;
    }
  }

  // 出力する
  int canDo = count / N;
  cout << canDo << endl;
}
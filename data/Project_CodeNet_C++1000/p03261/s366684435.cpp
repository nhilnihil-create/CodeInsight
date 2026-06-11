#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<string> W(N);

  cin >> W.at(0);

  for (int i = 1; i < N; i++)
  {
    cin >> W.at(i);

    // しりとり が成り立っているかどうか
    if (W.at(i - 1).back() != W.at(i).front())
    {
      cout << "No" << endl;
      return 0;
    }
  }

  // 配列重複削除
  sort(W.begin(), W.end());
  W.erase(unique(W.begin(), W.end()), W.end());

  // 同じ単語を使っているかどうか
  cout << (W.size() == N ? "Yes" : "No") << endl;
}

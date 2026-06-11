#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  int A, B;
  A = B = 0;
  cin >> n;
  vector<int> Cards(n);

  for (int i = 0; i < n; i++)
  {
    cin >> Cards.at(i);
  }

  for (int i = 0; i < n; i++)
  {
    int maxElementIndex = max_element(Cards.begin(), Cards.end()) - Cards.begin();
    int maxElement = *max_element(Cards.begin(), Cards.end());
    Cards.at(maxElementIndex) = 0;

    if (i % 2 == 0)
    {
      A += maxElement;
    }
    else
    {
      B += maxElement;
    }
  }
  cout << A - B << endl;
}

#include <iostream>

using namespace std;

int main()	{
  int n;
  cin >> n;
  int freq[4] = {0};
  for (int i = 0; i < 4; i++)	{
    int tmp = n % 10;
    freq[4 - i - 1] = tmp;
    n /= 10;
  }
  if (freq[0] == freq[1] && freq[1] == freq[2])	{
    cout << "Yes" << endl;
  }
  else if (freq[1] == freq[2] && freq[2] == freq[3])	{
    cout << "Yes" << endl;
  }
  else	{
    cout << "No" << endl;
  }
  return 0;
}
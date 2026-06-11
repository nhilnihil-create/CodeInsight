#include <iostream>
#include <string>
#include <vector>
#include <map>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  int n;
  cin >> n;

  std::map<int, int> even;
  std::map<int, int> odd;
  rep(i, n)
  {
    int v;
    cin >> v;
    if (i % 2 == 0)
    {
      even[v]++;
    }
    else
    {
      odd[v]++;
    }
  }

  int even_mx_1 = 0;
  int even_mx_2 = 0;
  int even_mx_num = 0;
  for (auto i = even.begin(); i != even.end(); i++)
  {
    if (even_mx_1 < i->second)
    {
      even_mx_num = i->first;
      even_mx_2 = even_mx_1;
      even_mx_1 = i->second;
    }
    else if (even_mx_2 < i->second)
    {
      even_mx_2 = i->second;
    }
  }

  int odd_mx_1 = 0;
  int odd_mx_2 = 0;
  int odd_mx_num = 0;
  for (auto i = odd.begin(); i != odd.end(); i++)
  {
    if (odd_mx_1 < i->second)
    {
      odd_mx_num = i->first;
      odd_mx_2 = odd_mx_1;
      odd_mx_1 = i->second;
    }
    else if (odd_mx_2 < i->second)
    {
      odd_mx_2 = i->second;
    }
  }

  if (odd_mx_num != even_mx_num)
  {
    cout << n - odd_mx_1 - even_mx_1 << endl;
  }
  else
  {
    cout << n - std::max(odd_mx_1 + even_mx_2, odd_mx_2 + even_mx_1) << endl;
  }

  return 0;
}

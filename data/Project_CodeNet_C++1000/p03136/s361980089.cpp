#include <iostream>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  int N;
  cin >> N;

  int mx = 0;
  int sum = 0;
  rep(i, N)
  {
    int l;
    cin >> l;
    if (mx < l)
      mx = l;
    sum += l;
  }

  if (mx >= sum - mx)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;

  return 0;
}

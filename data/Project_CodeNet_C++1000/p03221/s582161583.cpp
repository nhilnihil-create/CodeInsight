#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iomanip>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  int N, M;
  cin >> N >> M;

  vector<std::map<int, int>> cities_each_pref(N);

  rep(i, M)
  {
    int p, y;
    cin >> p >> y;
    p--;
    cities_each_pref[p][y] = i;
  }

  vector<string> cities(M);
  rep(i, N)
  {
    int pos = 1;
    for (auto it = cities_each_pref[i].begin(); it != cities_each_pref[i].end(); it++)
    {
      std::ostringstream oss;
      oss << std::setfill('0') << std::setw(6) << (i + 1);
      string p = oss.str();
      std::ostringstream oss2;
      oss2 << std::setfill('0') << std::setw(6) << pos;
      p += oss2.str();
      cities[it->second] = p;
      pos++;
    }
  }

  rep(i, M)
  {
    cout << cities[i] << endl;
  }

  return 0;
}

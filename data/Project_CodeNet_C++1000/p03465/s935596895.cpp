#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

const int bitsz = 4194304;

int main()
{

    int n, s = 0, rez = 0, x;
    cin >> n;

    vector<int> v(n + 1);

    bitset<bitsz> bs;

    bs[0] = 1;
    for (int i = 1; i <= n; i++) {
      cin >> x;
      s += x;
      bs |= bs << x;
    }

    for (int i = 0; i <= s / 2; i++)
      if (bs[i]) {
        rez = s - i;
      }

    cout << rez << "\n";
}

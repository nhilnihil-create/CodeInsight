#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <bitset>
#include <iomanip>
#include <deque>
#include <tuple>
#include <algorithm>

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;

    for (int i = 0; i < 3; i++) {
        if (s[i] != t[2-i]) {
            cout << "NO" << endl;
            return (0);
        }
    }
    cout << "YES" << endl;
}

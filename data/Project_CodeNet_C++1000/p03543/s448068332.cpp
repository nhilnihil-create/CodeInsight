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
    string s;
    char pre = '-';
    int cnt;

    cin >> s;

    for (int i = 0; i < 4; i++) {
        if (pre == s[i]) {
            cnt++;
        }
        else {
            cnt = 1;
            pre = s[i];
        }
        if (cnt > 2) {
            cout << "Yes" << endl;
            return (0);
        }
    }

    cout << "No" << endl;

}

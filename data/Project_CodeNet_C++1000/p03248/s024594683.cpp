#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
#include <tuple>
#include <map>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    if (char(s[0]) != '1' || char(s[n - 1]) != '0') {
        cout << -1 << endl;
        return 0;
    }

    int a[100010], b[100010], bef = 0, idx = 0;
    if (1) {
        for (int i = 0; i < n - 1; i++) {
            if (i < n / 2 && char(s[i]) != char(s[n - 2 - i])) {
                cout << -1 << endl;
                return 0;
            }
            a[idx] = bef;
            b[idx] = i + 1;
            idx++;
            /*
            a[idx] = n - 1 - bef;
            b[idx] = n - 2 - i;
            idx++;
            */
            if (char(s[i]) == '1') bef = i + 1;
        }
        for (int i = 0; i < idx; i++) {
            cout << a[i] + 1 << " " << b[i] + 1 << endl;
        }
    }

}
#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
#define ALL(x) (x).begin(), (x).end()
#define OUT(x) cout << (x) << endl
typedef long long ll;

int main() {
    string s;
    cin >> s;
    if (s.size() == 2) {
        OUT(s);
        return 0;
    } else {
        for (int i = 2; i >= 0; i--) {
            cout << s[i];
        }
        cout << endl;
    }
}

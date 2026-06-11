#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {        
    int a, b;
    cin >> a >> b;
    int res = 0;
    for (int i = a; i <= b; i++) {
        string s = to_string(i);
        int flag = 1;
        for (int j = 0; j < s.size() - 1 - j; j++) {
            if (s[j] != s[s.size() - 1 - j]) {
                flag = 0;
                break;
            }
        }
        res += flag;
    }
    cout << res << endl;
}

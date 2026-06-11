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
    string s = "MARCH";
    int n;
    cin >> n;
    unordered_map<char, long long int> um;
    for (int i = 0; i < n; i++) {
        string ss;
        cin >> ss;
        um[ss[0]]++;
    }
    long long int res = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                res += um[s[i]] * um[s[j]] * um[s[k]];
            }
        }
    }
    cout << res << endl;
}

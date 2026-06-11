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
    string s;
    cin >> s;
    if (s[0] == s[1] && s[1] == s[2]) {
        cout << "Yes" << endl;
        return 0;
    }
    if (s[1] == s[2] && s[2] == s[3]) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}

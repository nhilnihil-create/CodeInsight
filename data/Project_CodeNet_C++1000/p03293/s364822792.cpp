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
    string s, t;
    cin >> s >> t;
    
    int n = s.size();
    for (int i = 0; i < n; i++) {
        int flag = 1;
        for (int j = 0; j < n; j++) {
            if (s[j] != t[(j + i) % n]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}

#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

const int INF = 1e9;
const long long LINF = 1e18;
const double PI=3.14159265358979323846;

int main() {
    vector<int> d(5);
    for (int i = 0; i < 5; i++) {
        cin >> d[i];
    }

    int k;
    cin >> k;

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {   
            int n = d[j] - d[i];
            if (n > k) {
                cout << ":(" << endl;
                return 0;
            }
        }        
    }

    cout << "Yay!" << endl;

    return 0;
}
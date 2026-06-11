#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    int r = n;
    int l = -1;
    int m;
    int male_idx;
    cout << 0 << endl;
    string tmp_s;
    cin >> tmp_s;
    if (tmp_s == "Vacant") return 0;
    else if (tmp_s == "Male") {
        male_idx = 0;
    }
    else {
        male_idx = 1;
    }
    while(r-l>0) {
        m = (r + l) / 2;
        cout << m << endl;
        string s;
        cin >> s;
        if (s == "Vacant") break;
        else if (s == "Male") {
            if (m % 2 == male_idx) {
                l = m;
            }
            else {
                r = m;
            }
        }
        else if (s == "Female") {
            if (m % 2 == male_idx) {
                r = m;
            }
            else {
                l = m;
            }
        }
    }
    return 0;
}

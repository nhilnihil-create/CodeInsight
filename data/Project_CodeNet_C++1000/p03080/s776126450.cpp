#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int cntR = 0, cntB = 0;
    rep(i, n) {
        if(s[i] == 'R') {
            cntR++;
        }
        else {
            cntB++;
        }
    }

    if(cntR > cntB) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    cout << endl;
    return 0;
}
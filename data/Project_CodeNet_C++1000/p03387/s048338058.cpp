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

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    vector<int> abc(3, 0);
    rep(i, 3) cin >> abc[i];
    sort(abc.begin(), abc.end());
    if ((abc[2] - abc[0]) % 2 == 0 && (abc[2] - abc[1]) % 2 == 0) {
        cout << (abc[2] - abc[0]) / 2 + (abc[2] - abc[1]) / 2 << endl;
    } 
    else if ((abc[2] - abc[0]) % 2 == 1 && (abc[2] - abc[1]) % 2 == 1){
        cout << (abc[2] - abc[0]) / 2 + (abc[2] - abc[1]) / 2 + 1 << endl;
    }
    else if ((abc[2] - abc[0]) % 2 == 1) {
        cout << (abc[2] - abc[0] + 1) / 2 + (abc[2] - abc[1]) / 2 + 1 << endl;
    }
    else {
        cout << (abc[2] - abc[0]) / 2 + (abc[2] - abc[1] + 1) / 2 + 1 << endl;
    }


    return 0;
}

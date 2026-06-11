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
    
    vector<int> cnt(4);
    rep(i, 6) {
        int x;
        cin >> x;
        x--;
        cnt[x]++;
    }

    int flag = 0;
    rep(i, 4) {
        if(cnt[i] == 3) {
            flag = 1;
        }
    }

    if(flag) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }

    cout << endl;
    return 0;
}
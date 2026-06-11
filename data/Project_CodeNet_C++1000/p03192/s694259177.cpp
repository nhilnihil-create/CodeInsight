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
    cin >> n;

    int ans = 0;
    while(n > 0) {
        if(n%10 == 2) {
            ans++;
        }
        n /= 10;
    }

    cout << ans << endl;
    return 0;
}
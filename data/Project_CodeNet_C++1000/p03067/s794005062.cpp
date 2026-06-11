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
    int a, b, c;
    cin >> a >> b >> c;

    if((c-a)*(c-b) < 0) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    cout << endl;
    return 0;
}
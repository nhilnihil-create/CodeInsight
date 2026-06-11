#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
#define ll long long
#define rep(i, s, n) for(int i = s; i < n; i++)

int main() {
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    map<int, int> mp;
    vector<int> val;
    ll c1 = 0, c2 = 0;
    bool b = (k%2 == 0 ? true : false);
    rep(i, 1, n+1) {
        if(i%k == 0) {
            c1++;
        }
        if(b)
            if(i%k == k/2) c2++;
    }
    cout << c1*c1*c1+c2*c2*c2 << endl;
    return 0;
}
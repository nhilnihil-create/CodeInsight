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
    int m, k;
    cin >> m >> k;

    if(m == 0) {
        if(k == 0) {
            cout << 0 << " " << 0;
        }
        else {
            cout << -1;
        }
        cout << endl;
        return 0;
    }
    
    if(m == 1) {
        if(k == 0) {
            cout << 0 << " " << 0 << " " << 1 << " " << 1;
        }
        else {
            cout << -1;
        }
        cout << endl;
        return 0;
    }

    int p = 1;
    rep(i, m) {
        p *= 2;
    }
    
    if(k >= p) {
        cout << -1 << endl;
        return 0;
    }

    rep(i, p) {
        if(i != k) {
            cout << i << " ";
        }
    }
    cout << k << " ";
    for(int i = p-1; i >= 0; i--) {
        if(i != k) {
            cout << i << " ";
        }
    }
    cout << k;

    cout << endl;
    return 0;
}
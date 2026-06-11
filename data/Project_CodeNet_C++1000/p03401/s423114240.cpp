#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cstdio>
#include <cmath>
#include <climits>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int) n; i++)
#define rep1(i, n) for(int i = 1; i <= (int) n; i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n+2);
    a[0] = a[n+1] = 0;
    rep1(i,n) {
        cin >> a[i];
    }
    ll sum = 0;
    rep1(i,n+1) {
        sum += abs(a[i]-a[i-1]);        
    }
    rep1(i,n) {
        cout << sum + abs(a[i-1]-a[i+1]) - abs(a[i-1]-a[i]) - abs(a[i]-a[i+1]) << endl;
    }
    return 0;
}
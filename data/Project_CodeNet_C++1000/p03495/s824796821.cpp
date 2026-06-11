#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int) n; i++)
#define all(v) v.begin(),v.end()

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> cnt(200000);
    rep(i,n) {
        int a;
        cin >> a;
        cnt[a-1]++;
    }
    sort(all(cnt), greater<int>());
    int sum = 0;
    rep(i,k) {
        sum += cnt[i];
    }
    cout << n-sum << endl;
    return 0;
}
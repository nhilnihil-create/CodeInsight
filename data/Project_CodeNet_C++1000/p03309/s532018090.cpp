
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <list>
#include<map>
#include<set>
using namespace std;

int main() {
    int n, k, m,M ; long long ans =0;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        v.push_back(k-i-1);
    }
    sort(v.begin(), v.end());
    m = v[n / 2]; M = v[n / 2 + 1];
    for (int i = 0; i < n; i++) ans += abs(v[i] - m);
    if (n % 2 == 1) {
        for(int j=(M-m)/2; j<=(M-m)/2+1; j++){
            long long s = 0;
            for (int i = 0; i < n;i++) {
                s += abs(v[i] -j);
            }
            ans = min(ans, s);
        }
    }
    cout << ans << endl;
}
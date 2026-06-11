#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 998244353

using namespace std;
using ll = long long;
using ldb = long double;

int main() {
    int N;  cin >> N;
    vector<int> div(101);
    for (int i = 2; i <= N; i++) {
        int temp = i;
        for (int j = 2; j <= sqrt(temp); j++) {
            while (temp % j == 0) {
                div[j]++, temp /= j;
            }
        }
        if (temp > 1) div[temp]++;
    }
    /*
    for (int i = 2; i <= N; i++) {
        cout << i << " " << div[i] << endl;
    }
    */
    map<int, ll> cnt;
    for (int i = 2; i <= N; i++) {
        if (div[i] >= 74) cnt[75]++;
        if (div[i] >= 24) cnt[25]++;
        if (div[i] >= 14) cnt[15]++;
        if (div[i] >= 4)  cnt[5]++;
        if (div[i] >= 2)  cnt[3]++;
        if (div[i] >= 0)  cnt[1]++;
    }
    ll ans = cnt[75] + cnt[25] * (cnt[3] - 1) + cnt[15] * (cnt[5] - 1) 
        + ((cnt[5] * (cnt[5] - 1)/2) * (cnt[3] - 2));
    cout << ans << endl;
}

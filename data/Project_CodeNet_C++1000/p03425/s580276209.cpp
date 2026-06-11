#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <climits>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

using int64 = long long;


int main() {
    int n;
    cin >> n;
    map<char,int64> mp;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        mp[s.front()]++;
    }

    int64 ans = 0;
    vector top = {'M','A','R','C','H'};
    for (int i=0; i<5; i++) {
        for (int j=i+1; j<5; j++) {
            for (int k=j+1; k<5; k++) {
                ans += mp[top[i]] * mp[top[j]] * mp[top[k]];
            }
        }
    }

    cout << ans << endl;
}
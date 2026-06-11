#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main() { 
    int n;
    cin >> n;
    vector< pair<int, int> > a1, a2;
    int a,b;
    for (int i=0;i<n;i++) {
        cin >> a >> b;
        a1.push_back(make_pair(a, b));
    }
    for (int i=0;i<n;i++) {
        cin >> a >> b;
        a2.push_back(make_pair(a, b));
    }
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    vector<int> matched(n);
    for (int i = 0; i < n; ++i) matched[i] = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int j = 0, k = -1;
        int tmp = -1;
        while (a1[j].first < a2[i].first) {
            if (a1[j].second < a2[i].second && a1[j].second >= tmp && !matched[j]) {
                tmp = a1[j].second;
                k = j;
            }
            j++;
            if (j == n) break;
        }
        if (k >= 0 && k < n) {
            matched[k] = 1;
            ++ans;
        }
    }
    cout << ans << endl;
}
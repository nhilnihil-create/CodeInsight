#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

int main() {
    int n, k;   cin >> n >> k;
    string s;
    cin >> s;

    int i = 0, c0 = 0;
    vector<pair<int, int> > v;
    if (s[0] == '0')
        v.push_back(pair<int,int>(1, 0));
    while (i < n) {
        int start = i;
        while (i+1 < n && s[i] == s[i+1])
            i++;
        
        if (s[start] == '0')
            c0++;

        v.push_back(pair<int,int>(s[start], i-start+1));
        i++;
    }
    if (s[n-1] == '0')
        v.push_back(pair<int,int>(1, 0));

    k = min(k, c0);
    vector<int> sum(2*c0+2, 0);
    for (int i = 0; i < 2*c0+1; i++) {
        sum[i+1] = sum[i] + v[i].second;
    }

    int ans = 0;
    for (int i = 2*k+1; i <= 2*c0+1; i += 2) {
        ans = max(ans, sum[i]-sum[i-2*k-1]);
    }

    cout << ans << endl;

    return 0;
}
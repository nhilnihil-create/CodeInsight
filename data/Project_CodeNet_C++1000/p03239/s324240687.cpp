#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> ans;

    for(int i=0; i<n; i++) {
        int a,b;
        cin >> a >> b;
        if(b <= t) {
            ans.push_back(a);
        }
    }
    sort(ans.begin(), ans.end());

    if(ans.size() == 0) cout << "TLE" << endl;
    else cout << ans[0] << endl;
}
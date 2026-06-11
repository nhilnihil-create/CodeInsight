#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define P pair<int, int>
#define rep(i, s, n) for(int i = s; i < n; i++)

int main() {
    int n;
    cin >> n;
    vector<int> b(n);
    rep(i, 0, n) cin >> b[i];
    vector<int> ans(n);
    if(b[0] != 1) {
        cout << -1 << endl;
        return 0;
    }

    ans[0] = b[0];
    rep(i, 1, n) {
        auto itr = ans.begin()+(b[i]-1);
        //cout << "itr: " << *itr  << " " << *ans.begin()<< endl;
        if(b[i]-1 != i && *itr == 0) {
            cout << -1 << endl;
            return 0;
        }
        ans.insert(itr, b[i]);
    }
    rep(i, 0, n) {
        cout << ans[i] << endl;
    }
    return 0;
}
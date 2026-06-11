#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    vector<pair<int, int>> blue(n), red(n);
    rep(i, n) cin >> red.at(i).first >> red.at(i).second;
    rep(i, n) cin >> blue.at(i).first >> blue.at(i).second;
    sort(blue.begin(), blue.end());
    sort(red.begin(), red.end());
    rep(i, n) {
        int f = blue.at(i).first;
        int s = blue.at(i).second;
        int temp = -1, maximum = -1;
        rep(j, n) if(red.at(j).first < f) {
            if(maximum < red.at(j).second && red.at(j).second < s) {
                temp = j;
                maximum = red.at(j).second;
            }
        }
        if(temp != -1) {
            red.at(temp) = make_pair(INT_MAX, INT_MAX);
            ans++;
        }

    }
    
    cout << ans << endl;
}
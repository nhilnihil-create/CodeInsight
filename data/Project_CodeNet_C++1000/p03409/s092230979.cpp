#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    vector<int> d(n);
    vector<pair<int, int>> red(n);
    vector<pair<int, int>> blue(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i) >> b.at(i);
        red.at(i) = make_pair(a.at(i), b.at(i));
    }
    for (int i = 0; i < n; i++) {
        cin >> c.at(i) >> d.at(i);
        blue.at(i) = make_pair(c.at(i), d.at(i));
    }    
    
    sort(begin(red), end(red), compare);
    sort(begin(blue), end(blue));

    vector<bool> red_used(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (red_used.at(j)) {
                continue;
            }
            int blue_x = blue.at(i).first;
            int blue_y = blue.at(i).second;
            int red_x = red.at(j).first;
            int red_y = red.at(j).second;
            if (blue_x > red_x && blue_y > red_y) {
                red_used.at(j) = 1;
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
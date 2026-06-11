#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(2));
    for (int i = 0; i < n; i++) cin >> a.at(i).at(0);
    for (int i = 0; i < n; i++) cin >> a.at(i).at(1);
    
    int count = a.at(0).at(0);

    for (int i = 0; i < n; i++) {
        int tmpCount = 0;
        for (int j = 0; j <= i; j++) {
            tmpCount += a.at(j).at(0);
        }
        for (int j = i; j < n; j++) {
            tmpCount += a.at(j).at(1);
        }
        count = max(tmpCount, count);
    }
    cout << count << endl;

    return 0;
}
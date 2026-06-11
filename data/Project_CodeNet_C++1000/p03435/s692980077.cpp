#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> c(3, vector<int> (3, 0));
    for (long long i=0; i<3; i++) {
        for (long long j=0; j<3; j++) {
            cin >> c.at(i).at(j);
        }
    }
    vector <int> df(9);
    df.at(0) = c.at(0).at(0)-c.at(0).at(1);
    df.at(1) = c.at(0).at(1)-c.at(0).at(2);
    df.at(2) = c.at(0).at(2)-c.at(0).at(0);
    df.at(3) = c.at(1).at(0)-c.at(1).at(1);
    df.at(4) = c.at(1).at(1)-c.at(1).at(2);
    df.at(5) = c.at(1).at(2)-c.at(1).at(0);
    df.at(6) = c.at(2).at(0)-c.at(2).at(1);
    df.at(7) = c.at(2).at(1)-c.at(2).at(2);
    df.at(8) = c.at(2).at(2)-c.at(2).at(0);
    if (df.at(0)==df.at(3) && df.at(0)==df.at(6) && df.at(1)==df.at(4) && df.at(1)==df.at(7) && df.at(2)==df.at(5) && df.at(2)==df.at(8)) {
        cout << "Yes";
    }
    else cout << "No";
}
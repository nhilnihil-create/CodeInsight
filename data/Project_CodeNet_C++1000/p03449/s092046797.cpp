#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >>n;
    vector<int> at(n), au(n);
    for (int i = 0; i < n; i++) cin >> at.at(i);
    for (int i = 0; i < n; i++) cin >> au.at(i);

    int ret = 0;
    for (int i = 0; i < n; i++) {
        int t = 0;
        for (int k = 0; k <= i; k++) t += at.at(k);
        for (int j = i; j < n;  j++) t += au.at(j);
        ret = max(ret, t);
    }

    cout << ret << endl;
    return 0;
}
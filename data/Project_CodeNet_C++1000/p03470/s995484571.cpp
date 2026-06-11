#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    int step = 0;
    int minstep = 999;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < a.size(); i++) {
        cin >> a.at(i);
    }

    sort(a.rbegin(), a.rend());

    for (int i = 0; i < n; i++) {
        if (minstep > a.at(i)) {
            minstep = a.at(i);
            step++;
        }
    }

    cout << step << endl;

}
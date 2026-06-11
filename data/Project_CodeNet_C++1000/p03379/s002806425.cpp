#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    int x[n];
    vector<int> v;
    for (int i=0; i<n; i++) {
        cin >> x[i];
        v.push_back(x[i]);
    }
    sort(v.begin(), v.end());
    int medL = v[n/2-1], medR = v[n/2];
    for (int i=0; i<n; i++) {
        if (x[i] <= medL) {
            cout << medR << endl;
        } else {
            cout << medL << endl;
        }
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i=0; i<n; i++) {
        int h;
        cin >> h;
        v.push_back(h);
    }
    sort(v.begin(), v.end());
    int minDiff = 1000000000;
    for (int i=0; i+k-1<n; i++) {
        minDiff = min(minDiff, v[i+k-1]-v[i]);
    }
    cout << minDiff << endl;
}
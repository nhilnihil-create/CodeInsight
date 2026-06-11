#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, k; cin >>n >>k;
    vector<int> h;
    for (int i = 0; i < n; i++) {
        int tmp; cin >>tmp;
        h.push_back(tmp);
    }
    sort(h.begin(), h.end());
    int ret = 1000000001;
    for (int i = 0; i <= h.size() - k; i++) {
        ret = min(ret, h.at(i+k-1) - h.at(i));
    }
    cout << ret << endl;
    return 0;
}
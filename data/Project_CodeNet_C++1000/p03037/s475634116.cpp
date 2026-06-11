#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int maxOfL = 1, minOfR = n;
    for (int i=0; i<m; i++) {
        int l, r;
        cin >> l >> r;
        maxOfL = max(maxOfL, l);
        minOfR = min(minOfR, r);
    }
    cout << max(minOfR-maxOfL+1, 0) << endl;
}
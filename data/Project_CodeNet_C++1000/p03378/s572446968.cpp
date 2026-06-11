#include <iostream>
using namespace std;
int main() {
    int n, m, x;
    cin >> n >> m >> x;
    int l = 0, g = 0;
    int a;
    for (int i=0; i<m; i++) {
        cin >> a;
        if (a < x) {
            l++;
        } else {
            g++;
        }
    }
    cout << min(l, g) << endl;
}
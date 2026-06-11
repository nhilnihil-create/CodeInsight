#include "bits/stdc++.h"
using namespace std;

int main() {
    int n;
    cin >> n;
    vector< int> v(n);
    int mni = 0, mxi = 0;
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        if(v[i] < v[mni]) mni = i;
        if(v[i] > v[mxi]) mxi = i;
    }

    cout << 2 * n - 1 << endl;

    if(abs(v[mxi]) >= abs(v[mni])) {
        for(int i = 0; i < n; ++i) {
            cout << mxi + 1 << ' ' << i + 1<< endl;
        }

        for(int i = 0; i < n - 1; i++) {
            cout << i + 1 << ' ' << i + 2 << endl;
        }
    }

    else {
        for(int i = 1; i <= n; ++i) {
            cout << mni + 1 << ' ' << i << endl;
        }

        for(int i = n; i > 1; i--) {
            cout << i << ' ' << i - 1 << endl;
        }
    }


}

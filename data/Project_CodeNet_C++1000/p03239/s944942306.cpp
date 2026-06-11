#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n,t,c,tt;
    int mincost = INT_MAX;
    cin >> n >> t;

    for(int i=0;i<n;i++) {
        cin >> c >> tt;
        if(tt <= t) {
            if(mincost > c ) {
                mincost = c;
            }
        }
    }
    
    if(mincost == INT_MAX) {
        cout << "TLE\n";
    } else {
    cout << mincost << endl;
    }

    return 0;
}

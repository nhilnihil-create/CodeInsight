#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    cin >> n >> t;
    
    int mincost = 1001;
    for (int i = 0; i < n; i++) {
        int cost, time0;
        cin >> cost >> time0;
        if (time0 <= t) {
            mincost = min(mincost,cost);
        }
    }
    
    if (mincost == 1001) {
        cout << "TLE" << endl;
        return 0;
    }
    
    cout << mincost << endl;
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, tlim;
    cin >> n >> tlim;

    vector<int> c(n), t(n);
    for(int i = 0; i < n; i++) cin >> c[i] >> t[i];

    int ans = -1;
    int mincost = 10000;
    for(int i = 0; i < n; i++){
        if(t[i] <= tlim && c[i] < mincost){
            ans = i;
            mincost = c[i];
        }
    }

    if(ans == -1) cout << "TLE" << endl;
    else cout << mincost << endl;
    return 0;
}
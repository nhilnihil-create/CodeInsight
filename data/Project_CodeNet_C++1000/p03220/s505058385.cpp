#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, t, a;
    cin >> n >> t >> a;

    double diff = 1e5;
    int ans = -1;
    for (int i=0; i<n; i++){
        int h;
        cin >> h;
        double buf = abs((double)a - ((double)t - h*0.006));
        diff = min(diff, buf);
        if (diff == buf){
            ans = i + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
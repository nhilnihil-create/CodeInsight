#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, t, a, ans;
    double diff = pow(10, 6), tmp;
    cin >> n >> t >> a;
    int h[n];
    for (int i=0; i<n; i++) cin >> h[i];
    for (int i=0; i<n; i++){
        tmp = abs((t - h[i] * 0.006) - a);
        if (tmp < diff){
            diff = tmp;
            ans = i + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
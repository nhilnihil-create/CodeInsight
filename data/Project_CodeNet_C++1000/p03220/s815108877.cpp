#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t, a; cin >> n >> t >> a;
    vector<int> h(n);
    int reg_diff = INT_MAX;
    int reg_index;
    for(int i = 0; i < n; i++) {
        cin >> h[i];
        if(abs(t*1000-h[i]*6-a*1000)<reg_diff) {
            reg_diff = abs(t*1000-h[i]*6-a*1000);
            reg_index = i;
        }
    }
    cout << reg_index + 1 << endl;
    return 0;
}
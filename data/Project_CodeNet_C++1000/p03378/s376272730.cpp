#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, x, temp;
    cin >> n >> m >> x;
    int l = 0, r = 0;
    for(int i = 0; i < m; i++) {
        cin >> temp;
        if(temp < x) l++;
        else r++;
    }
    cout << min(l, r) << endl;
    return 0;
}

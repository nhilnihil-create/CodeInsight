#include <bits/stdc++.h>
using namespace std;

int main(){
    //nはお菓子の種類、xはグラム
    int n, x;
    cin >> n >> x;
    vector<int> m(n);
    for(int i=0; i<n; i++) cin >> m.at(i);
    int ans = 0;
    for (int i=0; i < n; i++) {
        x = x - m.at(i);
        ans++;
    }

    sort(m.begin(), m.end());

    while(x > 0) {
        if( x - m.at(0) >= 0) {
            x = x - m.at(0);
            ans++;
        }
        else break;
    }

    cout << ans << endl;
}
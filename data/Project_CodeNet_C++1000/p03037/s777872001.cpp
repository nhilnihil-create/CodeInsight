#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n>> m;
    int l = 1;
    int r = 100007;
    for (int i = 0; i < m; i++){
        int ll, rr;
        cin >> ll >> rr;
        l = max(l, ll);
        r = min(r, rr);
    }
    if (l > r) cout << 0 <<endl;
    else cout << r-l+1 <<endl;
    return 0;
}

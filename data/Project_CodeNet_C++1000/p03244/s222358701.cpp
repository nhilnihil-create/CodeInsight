#include<bits/stdc++.h>
using namespace std;
int guusuu[100005],kisuu[100005],mx1,mx2,x1,x2;
#define int long long 

signed main() {
    int n;
    cin >> n;
    int u;
    for(int i = 0; i < n; i++) {
        cin >> u;
        if(i%2 == 0) {
            guusuu[u]++;
            if(mx1 < guusuu[u]) {
                mx1 = guusuu[u];
                x1 = u;
            }
        }
        else{
            kisuu[u]++;
            if(mx2 < kisuu[u]) {
                mx2 = kisuu[u];
                x2 = u;
            }
        }
    }
    sort(guusuu,guusuu+100005);
    sort(kisuu,kisuu+100005);
    if(x1 != x2) {
        cout << n-mx1-mx2 << endl;;
    }
    else {
        cout << n-max(mx1+kisuu[100003],mx2+guusuu[100003]) << endl;
    }
}
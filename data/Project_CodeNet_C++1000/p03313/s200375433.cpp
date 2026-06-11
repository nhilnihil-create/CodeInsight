#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
const int N = 18;

int n;
int best[1<<N][3], ans[1<<N];

void insert(int mask, int val){
    auto a = best[mask];
    a[2] = val;
    if (a[2] > a[1]) swap(a[2], a[1]);
    if (a[1] > a[0]) swap(a[1], a[0]);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    forn(i,1<<n) {
        int x; cin >> x;
        insert(i,x);
    }
    forn(i,n) {
        forn(mask, 1<<n) if ((mask>>i)&1) {
            int nmask = mask - (1<<i);
            forn(j,2) insert(mask, best[nmask][j]);
        }
    }
    forsn(i,1,1<<n) {
        ans[i] = max(ans[i], best[i][0] + best[i][1]);
        ans[i+1] = max(ans[i+1], ans[i]);
        cout << ans[i] << '\n';
    }

    return 0;
}

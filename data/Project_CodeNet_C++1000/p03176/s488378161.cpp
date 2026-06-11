#include <bits/stdc++.h>
#define int long long
using namespace std;
 
struct Val {
    int val, i;
};
 
const int M = 1 << 18, N = 2*M;
 
Val a[N];
int maxi[N];
 
int getMax(int i) {
    int ans = 0;
    while(i > 0) {
        if(i % 2 == 1)
            ans = max(ans, maxi[i-1]);
        i /= 2;
    }
    return ans;
}
 
void insert(int i, int val) {
    while(i > 0) {
        maxi[i] = max(maxi[i], val);
        i /= 2;
    }
}
 
signed main() {
    /*
    freopen("exercise.in", "r", stdin);
    freopen("exercise.out", "w", stdout);
    */
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i].val;
        a[i].i = i;
    }
    sort(a, a+n, [](Val a, Val b){return a.val < b.val;});
    int p = a[0].val;
    a[0].val = 0;
    for(int i = 1; i < n; i++)
        if(p == a[i].val) {
            p = a[i].val;
            a[i].val = a[i-1].val;
        } else {
            p = a[i].val;
            a[i].val = a[i-1].val + 1;
        }
    sort(a, a+n, [](Val a, Val b){return a.i < b.i;});
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int pds; cin >> pds;
        int nb = getMax(a[i].val + M) + pds;
        insert(a[i].val + M, nb);
        ans = max(ans, nb);
    }
    cout << ans;
}
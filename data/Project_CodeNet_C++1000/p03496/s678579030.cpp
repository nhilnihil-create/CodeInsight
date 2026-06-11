#include <iostream>
#include <vector>
#include <queue>
#include<map>
#include<algorithm>
#include<set>
#define rep(i,n) for(int i = 0;i < n;i++)
#define rrep(i,n) for(int i = n-1;i >=0;i--)
#define ALL(a) a.begin(),a.end()
using namespace std;
int main() {
    int n,mx,mi; cin >> n; vector<int> a(n);
    rep(i, n) cin >> a[i];
    mx = *max_element(ALL(a)); mi = *min_element(ALL(a));
    cout << 2 * n - 1 << endl;
    if (abs(mx) >= abs(mi)) {
        int mxid = max_element(ALL(a)) - a.begin()+1;
        rep(i, n) {
            a[i] += mx;
            cout << mxid << " " << i+1 << endl;
        }
        rep(i, n-1)  cout << i + 1 << " " << i+2 << endl;
    }
    else {
        int miid = min_element(ALL(a)) - a.begin()+1;
        rep(i, n) {
            a[i] += mi;
            cout << miid << " " << i + 1 << endl;
        }
        rrep(i, n - 1) cout << i+2 << " " << i + 1 << endl;// 足す法、足されるほう
    }
}
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
int main(void) {
    int a, b; cin >> a >> b;
    int k; cin >> k;
    rep(i, k) {
        if(i%2 == 0) {
            if(a&1) a--;
            b += a/2;
            a = a/2;
        } else {
            if(b&1) b--;
            a += b/2;
            b = b/2;
        }
    }
    cout << a << " " << b << endl;
}

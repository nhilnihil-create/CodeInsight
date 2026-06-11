#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> l(n);
    rep(i,n) cin >> l[i];

    int ans = (n-3)*10+3*1*1000;
    rep(i,1<<(2*n)){
        int p = 0;
        int q = 0;
        int r = 0;
        int z = n-3;
        rep(j,n){
            int g = i>>(2*j)&0b11;
            int lj = l[j];
            if(g == 0) p += lj;
            else if(g == 1) q += lj;
            else if(g == 2) r += lj;
            else z--;
        }
        if(p == 0 || q == 0 || r == 0) continue;

        int mpi = 10*z+abs(p-a)+abs(q-b)+abs(r-c);
        ans = min(ans,mpi);
    }
    cout << ans << endl;
}

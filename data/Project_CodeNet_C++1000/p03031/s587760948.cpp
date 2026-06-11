#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)

int main(){
    int n, m; cin >> n >> m;
    vector<int> S(n);
    rep(k, m){
        int tmp; cin >> tmp;
        rep(i, tmp){
            int a; cin >> a; a--;
            S[a] |= 1 << k;
        }
    }
    int p = 0;
    rep(i, m){
        int tmp; cin >> tmp;
        p |= tmp << i;
    }
    int success = 0;
    rep(bit, (1<<n)){
        int ok = 0;
        rep(i, n){
            if (bit >> i & 1){
                ok ^= S[i];
            }
        }
        if (ok == p) success ++;
    }
    cout << success << endl;
}
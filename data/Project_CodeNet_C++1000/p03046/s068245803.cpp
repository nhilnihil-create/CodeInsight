#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define loop(i, a, n) for(int i = (a); i < (n); i++)
#define all(x) x.begin(), x.end()
using namespace std;
using ll = int64_t;

int main(){
    int m, k; cin >> m >> k;

    if(m == 0 && k == 0){
        cout << "0 0" << endl;
    } else if(m == 1 && k == 0) {
        cout << "0 0 1 1" << endl;
    } else if(m >= 2) {
        int limit = 1 << m;
        if(k >= limit) {
            cout << -1 << endl;
            return 0;
        }
        vector<int> a;
        rep(i, limit){
            if(i == k) continue;
            a.push_back(i);
        }
        rep(ri, 2){
            for(int num : a) cout << num << ' ';
            cout << k;
            if(!ri) {
                cout << ' ';
                reverse(all(a));
            } else cout << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}
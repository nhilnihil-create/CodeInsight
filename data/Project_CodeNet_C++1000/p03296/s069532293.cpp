#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector <int> a(n , 0);
    rep(i,n){
        cin >> a[i];
    }
    ll res = 0;
    rep(i,n - 1){
        if(a[i] == 0){
            continue;
        }
        if(a[i] == a[i + 1]){
            a[i + 1] = 0;
            res++;
            continue;
        }
    }
    cout << res << endl;
    return 0;
}

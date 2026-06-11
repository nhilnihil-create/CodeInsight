#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n)cin >> a[i];
    int mx = -1001001001;
    int mn = 1001001001;
    int mxi, mni;
    rep(i, n){
        if(mx < a[i]){
            mx = a[i];
            mxi = i;
        }
        if(mn > a[i]){
            mn = min(mn, a[i]);
            mni = i;
        }
    }

    if(mn >= 0){
        cout << n - 1 << endl;
        rep(i, n - 1){
            cout << i+1 << ' ' << i+2 << endl;
        }
    }else if(mx <= 0){
        cout << n - 1 << endl;
        rep(i, n - 1){
            cout << n-i << ' ' << n-1-i << endl;
        }
    }else if(mx >= -mn){
        cout << 2 * n - 1 << endl;
        rep(i, n)cout << mxi+1 << ' ' << i+1 << endl;
        rep(i, n - 1)cout << i+1 << ' ' << i+2 << endl;
    }else{
        cout << 2 * n - 1 << endl;
        rep(i, n)cout << mni+1 << ' ' << i+1 << endl;
        rep(i, n - 1)cout << n-i << ' ' << n-1-i << endl;
    }
    
}
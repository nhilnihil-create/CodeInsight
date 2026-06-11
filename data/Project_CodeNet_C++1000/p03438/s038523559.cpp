#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    int N;
    cin >> N;
    vi a(N), b(N), c(N);
    rep(i, N){
        cin >> a[i];
    }
    ll X = 0LL;
    rep(i, N) {
        cin >> b[i];
        c[i] =a[i] - b[i];
        X += c[i];
    }
    if(X>0) {
        cout << "No" << endl;
        return 0;
    }
    X = -X;
    ll A=0LL, B=0LL;
    rep(i, N) {
        if(c[i]>0) {
            B += c[i];
        } else {
            if(c[i]%2) {
                A += (1-c[i])/2;
                ++B;
            } else {
                A += (-c[i])/2;
            }
        }
    }
    if((X-A)*2 == (X-B) && X>=A) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}
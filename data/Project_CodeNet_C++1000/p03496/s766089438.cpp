#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<int> a(N);
    int big = 0;
    int bignum = -1;
    rep(i, N){
        cin >> a[i];
        if(abs(a[i]) > abs(big)){
            big = a[i];
            bignum = i;
        }
    }

    if(bignum == -1){
        cout << 0 << endl;
        return 0;
    }

    cout << 2 * N - 1 << endl;
    for (int i = 1; i <= N; i++){
        cout << bignum+1 << " " << i << endl;
    }

    if(big > 0){
        for (int i = 1; i < N; i++){
            cout << i << " " << i+1 << endl;
        }
    } else {
        for (int i = N; i > 1; i--){
            cout << i << " " << i-1 << endl;
        }
    }

    return 0;
}
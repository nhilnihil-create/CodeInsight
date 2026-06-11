#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    ll total = 0;
    int mi = 1001001001;
    bool check = false;
    int m = 0;
    rep(i, N){
        cin >> A[i];
        total += abs(A[i]);
        mi = min(mi, abs(A[i]));
        if(A[i] < 0) m++;
        if (A[i] == 0) check = true;
    }

    if(check || m%2 == 0){
        cout << total << endl;
    } else {
        cout << total - 2 * mi << endl;
    }

    return 0;
}
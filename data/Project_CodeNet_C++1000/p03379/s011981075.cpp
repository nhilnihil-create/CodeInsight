#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<int> X(N);
    vector<int> Xc(N);
    rep(i, N){
        cin >> X[i];
        Xc[i] = X[i];
    }
    sort(Xc.begin(), Xc.end());
    int n2 = N/2;
    rep(i, N){
        int x = X[i];
        int xn = lower_bound(Xc.begin(), Xc.end(), x) - Xc.begin();
        if(xn < n2){
            cout << Xc[n2] << endl;
        } else {
            cout << Xc[n2-1] << endl;
        }
    }

    return 0;
}
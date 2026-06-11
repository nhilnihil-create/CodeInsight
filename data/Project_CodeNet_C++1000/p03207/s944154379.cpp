#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int N;
    cin >> N;
    vector<int> V(N);
    rep(i,N) {
        cin >> V[i];
    }
    sort(V.begin(),V.end());
    int ans = 0; 
    rep(j,N) {
        if (j != N - 1) {
            ans += V[j];
        }
        else {
            ans += V[j]/2;
        }
    }
    cout << ans << endl;
    
}

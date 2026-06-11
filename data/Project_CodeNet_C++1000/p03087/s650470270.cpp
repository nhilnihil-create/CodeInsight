#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N, Q; cin >> N >> Q;
    string S; cin >> S;
    vector<int> ac(N);
    for (int i = 1; i < N; i++){
        ac[i] = ac[i-1];
        if(S[i] == 'C' && S[i-1] == 'A'){
            ac[i]++;
        }
        //cout << i << " " << ac[i] << endl;
    }
    rep(i, Q){
        int l, r; cin >> l >> r;
        l--; r--;
        int ans = ac[r] - ac[l];
        cout << ans << endl;
    }

    return 0;
}
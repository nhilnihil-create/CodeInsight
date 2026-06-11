#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N, H; cin >> N >> H;
    vector<int> a(N);
    vector<int> b(N);
    rep(i, N){
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int amax = a[N-1];
    int ans = 0;
    int bnow = N-1;
    bool ok = true;
    while(H > 0){
        if(ok && amax < b[bnow]){
            H -= b[bnow];
            if(bnow == 0){
                ok = false;
            } else {
                bnow--;
            }
            ans++;
        } else {
            ans += ((H-1) / amax) + 1;
            break;
        }
    }

    cout << ans << endl;
    

    return 0;
}
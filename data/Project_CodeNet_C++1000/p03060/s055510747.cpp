#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    int N;
    cin >> N;
    vector<int> V(N), C(N);
    int ans = -10000;
    rep(i, N) cin >> V[i];
    rep(i, N) cin >> C[i];
    for(int bit=0; bit<(1<<N); ++bit){
        int X=0, Y=0;
        for(int i=0; i<N; ++i){
            if((bit>>i)&1){
                X+=V[i];
                Y+=C[i];
            }
        }
        ans = max(ans, X-Y);
    }
    cout << ans << endl;
    return 0;

}

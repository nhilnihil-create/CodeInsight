#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (ll i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    int N, K;
    cin >> N >> K;
    int cnt = 0;
    int ans = 0;
    vector<int> A(N+1);
    rep(i, N){
        int a;
        cin >> a;
        if(A[a]==0) cnt++;
        A[a]++;
    }
    if(cnt<=K){
        cout << 0 << endl;
        return 0;
    }
    sort(all(A));
    rep(i, N){
        if(A[i]!=0){
            cnt--;
            ans+=A[i];
            if(cnt<=K) break;
        }
    }
    cout << ans << endl;
    return 0;
}

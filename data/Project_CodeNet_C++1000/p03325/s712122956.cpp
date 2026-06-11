#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    int N, ans=0;
    cin >> N;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    while(true){
        bool flag = false;
        rep(i, N){
            if(a[i]%2==0){
                a[i]/=2;
                flag = true;
            }
            if(flag) break;
        }
        if(!flag){
            cout << ans << endl;
            return 0;
        }
        ans++;
    }
    return 0;
}

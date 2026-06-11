#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, ans=0, tmp=INF;
vector<ll> A, B;

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        ll a, b;
        cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
        ans += b;
    }
    for(int i=0;i<N;i++) {
        if(A[i]!=B[i]) break;
        if(i==N-1) {
            cout << 0 << endl;
            return 0;
        }
    }
    for(int i=0;i<N;i++) {
        if(A[i]>B[i]) {
            tmp = min(tmp,B[i]);
        }
    }
    cout << ans-tmp << endl;
    return 0;
}
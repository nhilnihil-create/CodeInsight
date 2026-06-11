#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, ans=0, tmp=0;
vector<ll> A, B;

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        ll a, b;
        cin >> a >> b;
        ans -= b;
        A.push_back(a+b);
    }
    sort(A.begin(), A.end());
    for(int i=A.size()-1;i>=0;i-=2) {
        ans += A[i];
    }
    cout << ans << endl;
    return 0;
}
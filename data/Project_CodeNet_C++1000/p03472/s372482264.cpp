#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, H, ans=0, tmp=0;
vector<ll> A(MAXN, 0), B(MAXN, 0);

signed main(){
    cin >> N >> H;
    for(int i=0;i<N;i++) {
        ll a, b;
        cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    ll id = upper_bound(B.begin(), B.end(), A.back())-B.begin();
    for(int i=B.size()-1;i>=id;i--) {
        H-=B[i];
        ans++;
        if(H<=0) break;
    }
    if(H>0) {
        if(H%A.back()==0) ans += H/A.back();
        if(H%A.back()!=0) ans += 1+H/A.back();
    }
    cout << ans << endl;
    return 0;
}
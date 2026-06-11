#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 100000;

ll N, ans=0, tmp1=1000000005, tmp2=0;
vector<ll> A(MAXN, 0);

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> A[i];
        ans += abs(A[i]);
        tmp1 = min(tmp1, abs(A[i]));
        if(A[i]<0) tmp2++;
    }
    if(tmp2%2==1) ans -= 2*tmp1;
    cout << ans << endl;
    return 0;
}
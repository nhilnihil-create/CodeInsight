#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll A, B, ans=0, C[41], D[41];

signed main(){
    cin >> A >> B;
    A--;
    for(int i=0;i<41;i++) {
        ll e = pow(2, i+1);
        C[i] = (e/2)*(A/e);
        if(A%e-e/2+1>0) C[i] += A%e-e/2+1;
        D[i] = (e/2)*(B/e);
        if(B%e-e/2+1>0) D[i] += B%e-e/2+1;
    }
    /*
    for(int i=0;i<41;i++) {
        cout << " " << C[i];
    }
    cout << endl;
    for(int i=0;i<41;i++) {
        cout << " " << D[i];
    }
    */
    for(int i=0;i<41;i++) {
        if((D[i]-C[i])%2==1) {
            ans += pow(2, i);
        }
    }
    cout << ans << endl;
    return 0;
}
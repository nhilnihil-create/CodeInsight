#include<iostream>
#include<cmath>
#include<algorithm>
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
using namespace std;

int main(){
    ll N, Z, W;
    ll ans;
    cin >> N >> Z >> W;
    ll A[N];
    rep(i,N) cin >> A[i];
    if(N==1){
        ans = abs(A[0]-W);
    }else{
        ll tmp1 = abs(A[N-1]-W);
        ll tmp2 = abs(A[N-2]-A[N-1]);
        ans = max(tmp1, tmp2);
    }
    cout << ans << endl;
    return 0;
}
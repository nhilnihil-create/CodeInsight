#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    vector<ll> A(N),B(N),ABdif(N);
    ll sumA=0,sumB=0;
    rep(i,N) {
        cin >> A[i];
        sumA+=A[i];
        ABdif[i] = A[i];
    }
    rep(i,N){
        cin >> B[i];
        sumB += B[i];
        ABdif[i]-=B[i];
    }
    if(sumA<sumB){
        cout << -1 << endl;
        return 0;
    }
    sort(ABdif.rbegin(),ABdif.rend());
    ll d = 0;
    ll ans = 0;
    rep(i,N){
        if(B[i]>A[i]){
            d += B[i]-A[i];
            ans++;
        }
    }
    if(d==0){
        cout << 0 << endl;
        return 0;
    }
    ll s = 0;
    rep(i,N){
        s+=ABdif[i];
        ans++;
        if(d<=s){
            cout << ans << endl;
            return 0; 
        }
    }
    cout << ans << endl;
    return 0;
}
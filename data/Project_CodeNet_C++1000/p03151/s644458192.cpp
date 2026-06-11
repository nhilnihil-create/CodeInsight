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
    bool f = true;
    rep(i,N){
        if(A[i]<B[i]) f = false;
    }
    if(f){
        cout << 0 << endl;
        return 0;
    }
    if(sumA<sumB){
        cout << -1 << endl;
        return 0;
    }
    sort(ABdif.rbegin(),ABdif.rend());
    int ix = 0;
    ll st = 0;
    ll cnt = 0;
    rep(i,N){
        ll d = B[i]-A[i];
        if(d>0){
            while(d>st){
                st+=ABdif[ix];
                cnt++;
                ix++;
            }
            st-=d;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
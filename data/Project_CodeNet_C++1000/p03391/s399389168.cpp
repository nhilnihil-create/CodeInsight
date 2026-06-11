#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

const ll mod = 1e9 + 7;
const ll INF = -1*((1LL<<63)+1);
const int inf = -1*((1<<31)+1);

using namespace std;

int main(void){
    int N;
    cin >> N;
    ll ans = 0;
    vector<ll> A(N),B(N);
    ll dif = 0;
    int p = -1;
    ll sum = 0;
    rep(i,N){
        cin >> A[i] >> B[i];
        sum += A[i];
    }
    rep(i,N){
        // i 番目以外を0にすると考えると
        if(A[i]>B[i]){
            ll t = A[i]-B[i] + sum - A[i];
            ans = max(t,ans);
        }
    }
    cout << ans << endl;
}
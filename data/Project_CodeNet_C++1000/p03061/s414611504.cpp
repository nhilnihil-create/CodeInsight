#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    sort(A.rbegin(),A.rend());
    // 1つまで無視できる
    vector<ll> front_gcd(N),back_gcd(N);
    front_gcd[0] = A[0];
    back_gcd[N-1]  = A[N-1];
    for(int i=1;i<N;i++) front_gcd[i] = __gcd(front_gcd[i-1],A[i]);
    for(int i=N-2;i>=0;i--) back_gcd[i] = __gcd(back_gcd[i+1],A[i]);
    ll ans;
    for(int i=0;i<N;i++){
        if(i==0){
            ans = back_gcd[1];
        }else if(i==N-1){
            ans = max(ans,front_gcd[i-1]);
        }else{
            ans = max(ans,__gcd(front_gcd[i-1],back_gcd[i+1]));
        }
    }
    cout << ans << endl;
    return 0;
}
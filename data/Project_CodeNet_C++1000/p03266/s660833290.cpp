#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
#define tl 1'000'000'007
#define REP(i, n) for (ll i = 0; i < n; i++)
#define REREP(i, n) for (ll i = n; i >= 0; i--)
#define FOR(i, a, n) for (ll i = a; i < n; i++)
#define REFOR(i, n, a) for (ll i = n; i >= a; i--)
//kが奇数ならa,b,cはkで割り切れる
//　　偶数ならa,b,cはk/2で割り切れる
// priority que
//bit全探索
// mod_gcd

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false); 
    ll n,k;
    cin >> n >> k;
    ll cnt1= 0;
    ll cnt2= 0;
    if(k&1){ //奇数
        FOR(i,1,n+1){
            if(i%k==0) cnt1++;
        }
    } else{ //偶数
        FOR(i,1,n+1){
            cnt1 += (i%k == 0);
            cnt2 += (i%k == k/2);
        } 
    }
    cout << cnt1*cnt1*cnt1 + cnt2*cnt2*cnt2 << endl;
}

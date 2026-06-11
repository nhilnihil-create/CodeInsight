#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, k; cin >> n >> k;
    ll zero = 0;
    ll half = 0;
    ll ans = 1;
    if(k % 2 == 1){
        for(int i = 1; i <= n; ++i){
            if(i % k == 0)zero++;
        }
        rep(i,3) ans *= zero;
    }else{
        for(int i = 1; i <= n; ++i){
            if(i % k == 0) zero++;
            if(i % k == k/2) half++;
        }
        ans = zero*zero*zero + half*half*half;
    }
    cout << ans << endl;
}
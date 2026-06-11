#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main(){
    ll n,k; cin >> n >> k;
    ll ans = 100000000000;

    vector<ll> d(n-1),x(n);

    rep(i,n){
        cin >> x[i];
    }

    for(int i = 0; i < n-(k-1); i ++){
        if(x[i] < 0 && x[i+(k-1)] < 0){
            ans = min(ans,abs(x[i]));
        }else if(x[i] > 0 && x[i+(k-1)] > 0){
            ans = min(ans,x[i+(k-1)]);
        }else{
            ll left = abs(x[i]);
            ll right = abs(x[i+(k-1)]);

            ans = min(ans,min(left,right) + left + right);
        }
    }

    cout << ans;

}
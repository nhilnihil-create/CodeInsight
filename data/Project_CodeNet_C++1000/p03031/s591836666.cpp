#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

const unsigned int BIT_FLAG_0 = (1 << 0); // 0000 0000 0000 0001
const unsigned int BIT_FLAG_1 = (1 << 1); // 0000 0000 0000 0010
const unsigned int BIT_FLAG_2 = (1 << 2); // 0000 0000 0000 0100
const unsigned int BIT_FLAG_3 = (1 << 3); // 0000 0000 0000 1000
const unsigned int BIT_FLAG_4 = (1 << 4); // 0000 0000 0001 0000
const unsigned int BIT_FLAG_5 = (1 << 5); // 0000 0000 0010 0000
const unsigned int BIT_FLAG_6 = (1 << 6); // 0000 0000 0100 0000
const unsigned int BIT_FLAG_7 = (1 << 7); // 0000 0000 1000 0000


ll numOfBits(ll bits)
{
    ll num  = 0;

    for ( ; bits != 0 ; bits &= bits - 1 ) {
        num++;
    }

    return num;
}


int main() {
    ll n,m; cin >> n >> m;
    vector<ll> p(m);
    vector<ll> k(m);
    ll ans = 0;
    bool flag = true;

    rep(i,m){
        ll tmp; cin >> tmp;
        ll sum = 0;
        rep(j,tmp){
            ll s; cin >> s;
            sum += (1 << (s-1));
        }
        k[i] = sum;
    }

    rep(i,m) cin >> p[i];
/*
    rep(i,m){
        cout << numOfBits(k[i]&&2) << endl;
    }
*/


    for(int bit = 0; bit < (1 << n); bit ++){
        flag = true;
        rep(i,m){
            if((numOfBits(bit&k[i])%2 != p[i])) flag = false;
        }
        if(flag) {
            ans ++;
        }
    }

    cout << ans;

    return 0;
}

#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const ll MOD = 1e9 + 7;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

ll ans = 0;

void rec(ll n, ll m){
    ll tmp = m;
    ll flag[3] = {false,false,false};
    if(m > n) return;
    while(m != 0){
        if(m%10 == 3) flag[0] = true;
        if(m%10 == 5) flag[1] = true;
        if(m%10 == 7) flag[2] = true;
        m /= 10;
    }
    if(flag[0] && flag[1] && flag[2]) ans ++;

    rec(n,tmp*10 + 3);
    rec(n,tmp*10 + 5);
    rec(n,tmp*10 + 7);
}

int main(){
    ll n; cin >> n;
    rec(n,0);
    cout << ans;
}
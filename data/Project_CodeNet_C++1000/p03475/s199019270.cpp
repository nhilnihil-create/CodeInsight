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




int main() {


    ll n; cin >> n;
    vector<ll> c(n-1),s(n-1),f(n-1);
    ll time = 0;

    rep(i,n-1){
        cin >> c[i]  >> s[i] >> f[i];
    }

    rep(i,n-1){
        for(int j = i; j < n-1; j ++){
            if(j == i) time = s[j] + c[j];
            else{
                if(s[j] >= time) time = s[j] + c[j];
                else {
                    time = c[j] + (time/f[j])*f[j] + ((time%f[j] == 0)?0:f[j]);
                }
            }
        }
        cout << time << endl;
    }
    cout << 0 << endl;


    return 0;
}

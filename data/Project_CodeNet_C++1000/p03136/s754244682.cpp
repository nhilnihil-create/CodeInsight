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


    ll n,a,Max = -1,sum = 0; cin >> n;

    rep(i,n){
        cin >> a;
        sum += a;
        Max = max(a,Max);
    }

    if(sum-Max > Max) cout << "Yes";
    else cout << "No";



    return 0;
}

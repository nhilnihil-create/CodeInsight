//----------------------------おまじない
#pragma GCC optimize ("O3")
#pragma GCC target ("tune=native")
#pragma GCC target ("avx")
//----------------------------
#define FOR(i,j,n) for (int i=(j);i<(n);i++)
#define REP(i,n) for (int i=0;i<(n);i++)
#define REPN(i,n) for (int i=(n);i>0;i--)
#define I(n) scanf("%d", &(n))
#define LL(n) scanf("%lld", &(n))
#define pb(n) push_back((n))
#define mp(i,j) make_pair((i),(j))
#define eb(i,j) emplace_back((i),(j))
#include <bits/stdc++.h>
using namespace std;
//------------------------------typedef集
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef vector<vpi> vvpi;
typedef vector<vvi> vvvi;
typedef long long ll;
const int mod = 1000000009;

ll gcd(ll a, ll b){
    if (a < b) swap(a,b);
    if (a%b){
        return gcd(b,a%b);
    } else {
        return b;
    }
}

int t;
ll a,b,c,d;

int main(){
    I(t);
    REP(_,t){
        LL(a);
        LL(b);
        LL(c);
        LL(d);
        if (a < b){
            cout << "No" << endl;
            continue;
        }

        ll dgcd = gcd(b,d);
        a %= b;
        a %= dgcd;
        a += b - dgcd;

        if (d >= b && c >= a) { 
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
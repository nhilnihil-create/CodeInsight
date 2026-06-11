#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long

bool solve(int a,int b,int c,int d){
    if(b > min(a,d)) return false;
    if(c >= b) return true;
    int x = __gcd(b,d);
    if(b - x + a%x > c)return false;
    else return true;
}

signed main(){
    int t; cin >> t;
    REP(i,t){
        int a, b, c, d; cin >> a >> b >> c >> d;
        cout << ( solve(a,b,c,d) ? "Yes" : "No" ) << endl;;
    }
}
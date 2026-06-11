#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

#define INF (1ll<<60)


long long M = 998244353;

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

vector<long long> inv,fact,invfact;

long long choose(long long n, long long k){
    if(k<0||k>n)return 0;
    long long res = fact[n];
    res *= invfact[k];
    res %= M;
    res *= invfact[n-k];
    res %= M;
    return res;
}

int main(int argc, char const *argv[]) {
    long long n,a,b,k;cin>>n>>a>>b>>k;
    inv = vector<long long>(n+1);
    fact = vector<long long>(n+1);
    invfact = vector<long long>(n+1);
    inv[1]=1;
    fact[0]=1;
    invfact[0]=1;
    for(long long i=2;i<=n;++i){
        inv[i] = M - inv[M%i]*(M/i);
        inv[i] %= M;
        inv[i] += M;
        inv[i] %= M;
    }
    for(long long i=1;i<=n;++i){
        fact[i] = (fact[i-1]*i)%M;
        invfact[i] = (invfact[i-1]*inv[i])%M;
    }
    long long x,y;
    long long g = extGCD(a,b,x,y);
    if(k%g!=0){
        cout<<0<<endl;
        return 0;
    }
    x *= k/g;
    y *= k/g;
    long long s = x / (b/g);
    x -= s*b/g;
    y += s*a/g;
    long long res = 0,xx=x,yy=y;
    // ax + by = k
    while(xx>=0 && yy<=n){
        // cout<<xx<<" "<<yy<<endl;
        long long tmp = choose(n,xx)*choose(n,yy)%M;
        // cout<<choose(n,xx)<<" "<<choose(n,y)<<endl;
        res += tmp;
        res %= M;
        xx -= b / g;
        yy += a / g;
    }
    xx = x+b/g;
    yy = y-a/g;
    while(xx<=n && yy>=0){
        // cout<<xx<<" "<<yy<<endl;
        long long tmp = choose(n,xx)*choose(n,yy)%M;
        // cout<<choose(n,xx)<<" "<<choose(n,y)<<endl;
        res += tmp;
        res %= M;
        xx += b / g;
        yy -= a / g;
    }
    res += M;
    res %= M;
    cout<<res<<endl;
    return 0;
}
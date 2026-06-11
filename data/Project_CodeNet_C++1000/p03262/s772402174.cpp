#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

long long gcd(long long a, long long b){
    long long r;
    if(a<b) std::swap(a,b);
    if(b<1) return b;
    while((r=a%b)!=0){
        a = b; b = r;
    }
    return b;
}

long long solve(const std::vector<ll>& d, int n){
    long long k = d.back();
    rep(i,n-1){
        k = gcd(k,d[i]);
    }
    return k;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<ll> x(n+1), d(n,0);
    rep(i,n+1) std::cin >> x[i];

    std::sort(x.begin(),x.end());
    for(int i=0; i<n; i++){
        d[i] = x[i+1]-x[i];
    }

    std::cout << solve(d, n) << "\n";
    return 0;
}
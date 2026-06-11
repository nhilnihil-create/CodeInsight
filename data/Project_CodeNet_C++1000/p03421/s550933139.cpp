#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    ll n, a, b;
    scanf("%lld %lld %lld", &n, &a, &b);
    if(a+b-1 > n || a*b < n) { printf("%d\n",-1); return 0; }
    ll k = a*b-n; ll count = 1;
    rep(i,a){
        if(k == 0){
            count += b-1;
            rep(i,b) { printf("%lld ",count); count--; }
            count += b+1;
        }
        else if(k < b-1){
            count += b-k-1;
            rep(i,b-k) { printf("%lld ",count); count--; }
            count += b-k+1;
            k = 0;
        }
        else{
            printf("%lld ",count); count++;
            k -= b-1;
        }
    }
    printf("\n");
    return 0;
}
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll A,B,C,D;

ll gcd(ll a, ll b){
    return b==0 ? a : gcd(b, a%b);
}

void solve(){
    if (A < B || D < B) {
        printf("No\n");
        return;
    }
    if (C >= B) {
        printf("Yes\n");
        return;
    }
    //讨论的式子：C < A-xB+yD < B 是不可以的
    ll m_gcd = gcd(B, D);
    ll ans = (A-C-1)/m_gcd - (A-B)/m_gcd;
    if (ans > 0) {
        printf("No\n");
    }
    else printf("Yes\n");
    return;
}

void input(){
    int T;
    scanf("%d",&T);
    while (T--){
        scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
        solve();
    }
}

int main(){
    input();
    return 0;
}
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

const int mod = 1e9+7;
#define ll long long int
const double epsilon = 1e-7;

ll mi(ll x, ll y){
    if(x<y)return x;
    return y;
}
ll a[300];
ll b[300];
ll c[300];
ll d[300];
bool ans[300];
ll gcd(ll a, ll b){
    if(a < b){
        ll t = a;
        a = b;
        b = t;
    }
    if(a % b == 0)return b;
    else return gcd(b, a%b);
}
int main(void){
    int t;
    scanf("%d", &t);
    for(int i = 0;i < t;i++)scanf("%lld %lld %lld %lld", &a[i], &b[i], &c[i], &d[i]);
    for(int i = 0;i < t;i++){
        if(a[i] < b[i]|| d[i] < b[i]){
            ans[i] = false;
            continue;
        }
        a[i] -= (a[i]-c[i])/b[i]*b[i];
        //printf("%d %lld\n", i+1, a[i]);
        if((a[i] < b[i] && c[i] < a[i])|| d[i] < b[i]){
            ans[i] = false;
            continue;
        }
        ll g = gcd(b[i], d[i]);
        ll e = a[i] - ((a[i] - b[i])/g + 1)*g;
        if(e < b[i] && e > c[i])ans[i] = false;
        else ans[i] = true;
    }
    for(int i = 0;i < t;i++){
        if(ans[i])printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

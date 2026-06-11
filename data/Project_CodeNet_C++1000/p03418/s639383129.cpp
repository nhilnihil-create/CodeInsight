#include        <map>
#include      <cmath>
#include      <queue>
#include     <string>
#include     <cstdio>
#include     <vector>
#include    <cstring>
#include   <iostream>
#include  <algorithm>
using namespace std;
#define ll long long
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 100+5;
const ll mod = 1e9+7;

int main(){
    ll n , m, ans = 0;
    scanf("%lld%lld",&n,&m);
    if(m==0){
        printf("%lld\n",n*n);
        return 0;
    }
    for(ll b = m+1;b<=n;++b){
        ans += n/b*(b-m);
        ans += max(0ll,n%b-m+1);
    }
    printf("%lld\n",ans);
    return 0;
}

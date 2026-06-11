#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int Max=1e6+7;
ll a,b,c,k;

int main(){
    ios::sync_with_stdio(0);
    scanf("%lld%lld%lld",&a,&b,&c);
    scanf("%lld",&k);
    if(k%2==0) printf("%lld\n",a-b);
    else printf("%lld\n",b-a);
    return 0;
}
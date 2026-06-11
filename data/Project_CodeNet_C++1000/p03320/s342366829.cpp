#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll MAX=16;
ll k,p10[MAX]={1,};
ll sum(ll x){
    if(x==0) return 0ll;
    return sum(x/10ll)+x%10ll;
}
int main(){
    ll now=0;
    scanf("%lld",&k);
    for(ll i=1;i<16;i++) p10[i]=p10[i-1]*10ll;
    for(ll i=0;i<k;i++){
        ll pt=0;
        now++;
        while(now>sum(now)*p10[pt]){
            now+=(9ll-now/p10[pt]%10ll)*p10[pt];
            pt++;
        }
        printf("%lld\n",now);
    }
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MAX=40;
const ll INF=0x3f3f3f3f;
const ll MOD=998244353;
ll N,ans;
char S[MAX],s1[MAX],s2[MAX];
string tmp;
map<string,ll> m[MAX];
int main(){
    scanf("%lld%s",&N,S);
    for(ll i=0;i<N;i++) s1[i]=S[i],s2[i]=S[2*N-1-i];
    for(ll i=0;i<(1<<N);i++){
        ll cnt=0;
        tmp.clear();
        for(ll j=0;j<N;j++) if((i>>j)&1) tmp.append(1u,s1[j]),cnt++;
        for(ll j=N-1;j>=0;j--) if(!((i>>j)&1)) tmp.append(1u,s1[j]);
        m[cnt][tmp]++;
    }
    for(ll i=0;i<(1<<N);i++){
        ll cnt=0;
        tmp.clear();
        for(ll j=0;j<N;j++) if((i>>j)&1) tmp.append(1u,s2[j]),cnt++;
        for(ll j=N-1;j>=0;j--) if(!((i>>j)&1)) tmp.append(1u,s2[j]);
        ans+=m[cnt][tmp];
    }
    printf("%lld\n",ans);
}

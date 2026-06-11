#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
#define all(v) v.begin(),v.end()
#define endl "\n"
#define clr(n, r) memset(n,r,sizeof(n))
typedef bitset<16> MASK;

void fast() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}
vector<vector<int>>submasks(1<<16);
ll gVal[1<<16];
ll arr[17][17],dp[1<<16];
ll ans(MASK m){
    if(!m.count())return 0;
    ll &ret=dp[m.to_ulong()];
    if(~ret)return ret;
    ret=-1e15;
    for (int i = 0; i < submasks[m.to_ulong()].size(); ++i) {
        MASK t=submasks[m.to_ulong()][i];
        ll val=gVal[t.to_ulong()];
        t.flip();
        t&=m;
        ret=max(ret,val+ans(t));
    }
    return ret;
}
int main() {
    fast();
    for (int i = 0; i <(1<<16) ; ++i)for(int s=i;s;s=(s-1)&i)submasks[i].push_back(s);
    int n;cin>>n;
    for (int j = 0; j <n ; ++j) {
        for (int i = 0; i <n ; ++i) {
            cin>>arr[j][i];
        }
    }
    for (int k = 0; k <submasks[(1<<16)-1].size() ; ++k) {
        MASK m=submasks[(1<<16)-1][k];
        for (int i = 0; i <16 ; ++i) {
                for (int j = i+1; j <16; ++j)
                    if(m[i]&&m[j])
                    gVal[m.to_ulong()]+=arr[i][j];
        }
    }
    clr(dp,-1);
    MASK m;m.flip();
    cout<<ans(m);



}

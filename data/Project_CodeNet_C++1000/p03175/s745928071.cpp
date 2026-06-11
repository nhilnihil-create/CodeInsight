#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,a,b;
vector<int> V[100005];
const ll MOD=1000000007;
int bio[100005];
ll dpW[100005];
ll dpB[100005];


pair<ll,ll> dfs (int a) {
    dpW[a]=1;
    dpB[a]=1;
    for (int b : V[a]) {
        if (bio[b]==1) {continue;}
        bio[b]=1;
        pair<ll,ll> ans=dfs(b);
        dpW[a]*=(ans.first+ans.second);
        dpB[a]*=ans.first;
        dpW[a]%=MOD;
        dpB[a]%=MOD;
    }
    if (dpW[a]==0) {dpW[a]++;}
    return {dpW[a],dpB[a]};

}

int main() {
    cin >> n;
    for (int i=0;i<n-1;i++) {
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }

    for (int i=1;i<=n;i++) {
        if (V[i].size()==1) {a=i;break;}
    }
    bio[a]=1;
    dfs(a);
    cout << (dpW[a]+dpB[a])%MOD << endl;
}



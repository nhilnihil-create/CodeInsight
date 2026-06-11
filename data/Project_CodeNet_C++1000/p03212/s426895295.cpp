/**
*    created: 08.05.2020 08:00:40
**/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int inf =1000000000;
vector<ll> A;
ll n;
void dfs(ll cur,int use,ll &an){
    if(cur>n){
        return;
    }
    if (use==0b111){
        an++;
    }
    //cur=357,537,753,3357,3537,3753,...
    //cur>=nでストップ,
    dfs(10 * cur + 7, use | 0b001, an);
    dfs(10 * cur + 5, use | 0b010, an);
    dfs(10 * cur + 3, use | 0b100, an);
}

int main() {
    cin >> n;
    ll ans=0;
    dfs(0, 0,ans);
    cout << ans << endl;
}
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
const int mod = 1e9 + 7;
const int N = 100005;
vector<int>g[N];
pair<int,int> dfs(int x,int p){
    int a = 1;
    int b = 0;
    for(int i : g[x]){
        if(i == p){
            continue;
        }
        pair<int,int> pr = dfs(i,x);
        int temp = a;
        a = (a * pr.second) % mod;
        b = (((temp*pr.first)%mod) + ((b*(pr.first+pr.second))%mod)) % mod;
        a %= mod;
        b %= mod;
    }
    return {a,(a+b)%mod};
}
int32_t main(){
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    pair<int,int> ans = dfs(1,0);
    cout<<(ans.first+ans.second)%mod<<endl;
}
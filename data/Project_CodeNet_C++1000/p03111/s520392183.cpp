#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
const ll MOD=1000000007;
const ll INF=1<<27;
int n,a,b,c;
vector<int> l(10);
int ans=INF;
void dfs(int depth,vector<int> v){
    if(depth==n){
         map<ll, ll> mp;
        rep(i, n) {
            if (v[i] == 3) continue;
            mp[v[i]]++;
        }
        if (mp.size() != 3) return;
        else {
            vector<int> sum(3,0);
            vector<int> cnt(3,0);
            for(int i=0;i<n;i++){
            if(v[i]==0)sum[0]+=l[i],cnt[0]++;
            if(v[i]==1)sum[1]+=l[i],cnt[1]++;
            if(v[i]==2)sum[2]+=l[i],cnt[2]++;
            }
             int ret=0;
             int tmp=0;
             tmp=(cnt[0]-1)+(cnt[1]-1)+(cnt[2]-1);
               ret=abs(a-sum[0])+abs(b-sum[1])+abs(c-sum[2])+10*tmp;
               ans=min(ans,ret);
               return;
        }
    }
    for(int i=0;i<4;i++){
        v[depth]=i;
        dfs(depth+1,v);
    }
}
int main(){
 cin>>n>>a>>b>>c;
 l.resize(n);
 rep(i,n)cin>>l[i];
 vector<int> v(n,0);
 dfs(0,v);
 cout << ans << endl;
}
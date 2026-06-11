#include <bits/stdc++.h>
using namespace std;

int N,D,ans=0;
vector<int> cnt(13,0);

void dfs(vector<int> v,int now){
    if (now==13){
        sort(v.begin(),v.end());
        int Min=50,n=v.size();
        for (int i=0;i<n;++i){
            int x=abs(v[(i+1)%n]-v[i]);
            Min=min(Min,min(x,24-x));
        }
        ans=max(ans,Min);
        return;
    }
    if (cnt[now]==1){
        vector<int> u=v;
        u.emplace_back(now);
        dfs(u,now+1);
        u.back()*=-1; u.back()+=24;
        dfs(u,now+1);
    } else if (cnt[now]==2){
        vector<int> u=v;
        u.emplace_back(now);
        u.emplace_back(24-now);
        dfs(u,now+1);
    } else dfs(v,now+1);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for (;N--;) cin >> D,++cnt[D];
    if (cnt[0]){cout << 0 << '\n'; return 0;}
    for (int i=1;i<13;++i)
        if (2<cnt[i]){cout << 0 << '\n'; return 0;}
    vector<int> init={0};
    dfs(init,1);
    cout << ans << '\n';
}
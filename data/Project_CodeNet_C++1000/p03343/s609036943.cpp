#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
 
    int n,k,q;
    cin>>n>>k>>q;
    ll a[n];
    pair<ll,ll> p[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        p[i] = make_pair(a[i],i);
    }
    sort(p,p+n);
    map<ll,ll> mp;
    mp[n] = 1;
    ll ans = 1e18;
    for(int mini=0;mini<=n;mini++){
        if(mini) mp[p[mini-1].second]++;
        int cnt=0;
        priority_queue<int,vector<int>,greater<int>> que;
        for(int i=0;i<n;i++){
            if(mp[i]==0){
                cnt++;
            }
            if(mp[i+1]){
                if(cnt>=k){
                    priority_queue<int,vector<int>,greater<int>> que2;
                    for(int j=i-cnt+1;j<=i;j++){
                        que2.push(a[j]);
                    }
                    while(que2.size()>=k){
                        que.push(que2.top());
                        que2.pop();
                    }
                }
                cnt = 0;
            }
        }
        if(que.size()<q) break;
        ll ret = -que.top();
        for(int i=1;i<q;i++){
            que.pop();
        }
        ret += que.top();
        ans = min(ans,ret);
    }
    cout<<ans<<endl;

}

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define All(v) (v).begin(),(v).end()
int dy[8] = {-1,0,1,0,-1,1,1,-1};
int dx[8] = {0,1,0,-1,1,1,-1,-1};
const int mod = 1000000007;
const int inf = mod*mod;
const int d5 = 100005;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int> cnt(60,0),x(60,0);
    for(auto it:a){
        for(int i=0;i<50;i++){
            if(it&(1ll<<i))cnt[i]++;
        }
    }
    for(int i=0;i<60;i++){
        if((2*cnt[i]<n)&&((1ll<<i)<=k))x[i]=1;
    }
    int X=0;
    for(int i=0;i<60;i++)if(x[i])X|=(1ll<<i);
    int res=0;
    if(X<=k)for(auto it:a)res+=(it^X);
    for(int i=60;i>=0;i--){
        if(x[i]){
            X-=(1ll<<i);
            if(X<=k){
                int tmp=0;
                for(auto it:a)tmp+=(it^X);
                res=max(res,tmp);
                X+=(1ll<<i);
            }
        }
    }
    cout<<res<<endl;
}
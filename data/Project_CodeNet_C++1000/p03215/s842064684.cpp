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
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)a[i]+=a[i-1];
    vector<int> v;
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            v.push_back(a[j]-a[i]);
        }
    }
    //1e6個の数列が与えられるのでこの中からk個選んでsubsetをつくりそのANDを最大化する
    //上から貪欲にそのbitを立てられるか調べる
    int res=0;
    for(int b=60;b>=0;b--){
        vector<int> vv;
        int now=(1ll<<b);
        int cnt=0;
        for(auto it:v){
            if(it&now){
                vv.push_back(it);
                cnt++;
            }
        }
        if(cnt>=k){
            //cout<<b<<endl;
            res+=now;
            v=vv;
        }
    }
    cout<<res<<endl;
}

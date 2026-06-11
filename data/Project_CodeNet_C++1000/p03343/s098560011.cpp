
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (int)(1000000007)
#define f first
#define s second
#define debug1(x) cerr<<x<<"\n"
#define debug2(x,y) cerr<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<"\n"
#define nl cerr<<"\n";
#define pq priority_queue
#define inf 9999999999999999
#define test cerr<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 4015
#define mxnn 2000005
int black[mxn][mxn],white[mxn][mxn],bpos[mxn],wpos[mxn],dp[mxn][mxn];
int32_t main(){
sp;
int n,k,q;
cin >>n >>k >>q;
int arr[n+1];
for(int i = 1;i<=n;i++) cin >>arr[i];
int mx = 0,mn = inf;
for(int i = 1;i<=n;i++){
    mx = max(mx,arr[i]);
    mn = min(mn,arr[i]);
}
int ans = inf;
for(int y = 1; y<=n;y++){
    int x = arr[y];
    vector<vector<int> >v;
    int i = 1;
    while(i<=n){
            vector<int>a;
        while(i<=n&&arr[i]>=x){
            a.pb(arr[i]);
            i++;
        }
        v.pb(a);
        i++;
    }
    vector<int>c;
    for(int i = 0;i<v.size();i++){
        sort(v[i].begin(),v[i].end());
        vector<int>p;
        if(v[i].size()>=k){
            for(int j = 0;j<=v[i].size()-k;j++){
                c.pb(v[i][j]);
            }
        }
    }
    sort(c.begin(),c.end());
    if(c.size()>=q){
        int mxx = 0;
        for(int i = 0;i<q;i++) mxx = max(mxx,c[i]);
        ans = min(ans,mxx-x);
    }
}
cout<<ans;
return 0;
}

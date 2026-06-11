#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ppb pop_back()
#define ALL(a) (a).begin(),(a).end()
#define int long long
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k; cin >> n >> k;
    vector<P> v;
    rep(i,n){
        int t,d; cin >> t >> d;
        t--;
        v.pb({d,t});
    }
    sort(ALL(v),greater<P>());
    vector<bool> used(n,0);
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<ll> ans(n+1,0);
    ll res=0,hoge=0;
    rep(i,k){
        res+=v[i].fi;
        if(!used[v[i].se]){
            used[v[i].se]=1;
            hoge++;
        }else{
            pq.push(v[i].fi);
        }
    }
    ans[hoge]=res;
    for(int i=k;i<n;i++){
        if(pq.empty()) break;
        if(!used[v[i].se]){
            used[v[i].se]=1;
            hoge++;
            ans[hoge]=ans[hoge-1]+v[i].fi-pq.top();
            pq.pop();
        }
    }
    ll fuga=0;
    rep(i,n+1){
        if(ans[i]!=0) ans[i]+=i*i;
        chmax(fuga,ans[i]);
    }
    cout << fuga << endl;
}

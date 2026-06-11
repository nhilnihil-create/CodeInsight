#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=1e9+7;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;cin >> n >> k;
    vector<vector<ll>> a(n);
    for(int i=0;i<n;i++){
        ll t,d;cin >> t >> d;
        t--;
        a[t].push_back(d);
    } 
    for(int i=0;i<n;i++){
        if(a[i].size()!=0){
            sort(a[i].begin(),a[i].end(),greater<ll>());
        }
        else{
            a[i].push_back(-inf);
        }
    }
    sort(a.begin(),a.end(),[&](auto x,auto y){return x[0]>y[0];});
    priority_queue<ll> pq;
    ll sum=0;
    for(int i=0;i<k;i++){
        sum+=a[i][0];
        for(int j=1;j<a[i].size();j++){
            pq.push(a[i][j]);
        }
    }
    for(int i=k;i<n;i++){
        for(int j=0;j<a[i].size();j++){
            pq.push(a[i][j]);
        }
    }
    ll ans=sum+k*k;
    for(ll i=k-1;i>=1;i--){
        ll u=a[i][0],v=pq.top();
        if(u<v){
            pq.pop();
            pq.push(u);
            sum+=v;
            sum-=u;
        }
        chmax(ans,sum+i*i);
    }
    cout << ans << endl;
}
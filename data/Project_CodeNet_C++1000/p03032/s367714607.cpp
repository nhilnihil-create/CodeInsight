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
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define repp(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

int main(){
    int n,k; cin >> n >> k;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];
    ll ans=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i+j==0||i+j>n||i+j>k) continue;
            priority_queue<ll,vector<ll>,greater<ll>> pq;
            ll res=0;
            rep(kk,i){
                pq.push(v[kk]);
                res+=v[kk];
            }
            rep(kk,j){
                pq.push(v[n-1-kk]);
                res+=v[n-1-kk];
            }
            int cnt=k-i-j;
            while((!pq.empty())&&pq.top()<0&&cnt>0){
                res-=pq.top(); pq.pop();
                cnt--;
            }
            chmax(ans,res);
        }
    }
    cout << ans << endl;
}

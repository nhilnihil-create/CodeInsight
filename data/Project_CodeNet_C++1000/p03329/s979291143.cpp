//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
//using Graph = vector<vector<pair<ll,ll>>>;
const int mod =1e+9+7;

const int dy[4]={0,1,0,-1};
const int dx[4]={1,0,-1,0};
const ll INF=1e10;

int main(){
    ll n; cin>>n;
    ll ans=n;
    for(int i=0;i<=n;i++){
        ll  cnt=0;
        ll t=i;
        while(t>0){
            cnt+=t%6;
            t/=6;
        }
        t=n-i;
        while(t>0){
            cnt+=t%9;
            t/=9;
        }
        ans=min(ans,cnt);
    }
    cout<<ans<<endl;
}










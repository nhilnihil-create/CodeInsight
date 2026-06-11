// 今日はお盆前の最終出社日です
// いい加減寝ろ

#include <bits/stdc++.h>
#define mod 1000000007
#define INF LLONG_MAX
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define all(x) (x).begin(),(x).end()
using namespace std;
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};
bool comp(pair<ll, ll> a, pair<ll , ll> b) {
    // 基本はfirstで比較
    if(a.first != b.first){
         return a.first < b.first; // 昇順
        //return a.first > b.first; // 降順
    }

    // それ以外はsecondで比較
    if(a.second != b.second){
        return a.second > b.second;
    }else{
        // どちらも同じ
        return true;
    }
}

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,c,d,n,maxi=0,f=0,mini=INF,sum=0;
    ll h,w;
    ll m;
    cin>>n>>m;
    vector<pair<ll,ll>> p(m);
    rep(i,m){
        cin>>a>>b;
        p[i]=make_pair(b,a);
    }
    sort(all(p),comp);
    ll r=0;
    rep(i,m){
        if(p[i].second>=r) {
            sum++;
            r=p[i].first;
        }
    }
    cout<<sum<<endl;
}

#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf=1e9+7;
const int mod=998244353;
int main(){
    ll m,k;cin>>m>>k;
    if(k==0){
        rep(i,1<<m){
            cout<<i<<' '<<i<<' ';
        }
        cout<<endl;
        return 0;
    }
    if((1<<m)<=k||(m==1&&k==1)){
        cout<<-1<<endl;
        return 0;
    }
    cout<<0<<' '<<k<<' '<<0<<' ';
    REP(i,1,1<<m){
        if(i!=k)cout<<i<<' ';
    }
    cout<<k<<' ';
    for(int i=(1<<m)-1;i>0;i--){
        if(i!=k)cout<<i<<' ';
    }
    cout<<endl;
}
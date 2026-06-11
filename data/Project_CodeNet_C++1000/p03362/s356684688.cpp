#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define lowbit(x) x&(-x)
#define iter set<int>::iterator

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

const int N = 1e5+5;
const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const int dir[4][2]={-1,0,1,0,0,-1,0,1};
const int exdir[4][2]={1,1,1,-1,-1,1,-1,-1};

ll qpow(ll x,ll y){
    ll ans=1,t=x;
    while(y>0){
        if(y&1)ans*=t,ans%=mod;
        t*=t,t%=mod;
        y>>=1;
    }
    return ans%mod;
}

void solve(){
    int t;cin>>t;
    set<int>s;
    for(int i=3;i<=55555;i++){
        if(i%10==3){
            int f=1;
            for(int j=2;j*j<i;j++)
                if(i%j==0)f=0;
            if(f)s.insert(i);
        }
    }
    for(int i:s){
        if(t)cout<<i<<' ';
        else break;
        t--;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //int t;cin>>t;
    //while(t--)solve(),cout<<'\n';
    solve();
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const ll inf=1e9+7;
const ll mod=998244353;
signed main(){
    int n;cin>>n;
    int ng=-1,ok=n;
    vector<int>a(n);
    rep(i,n)cin>>a[i];
    while(ok-ng>1){
        int mid=ng+(ok-ng)/2;
        map<ll,ll>ma;
        bool f=1;
        int la=0;
        rep(i,n){
            if(la<a[i]){
                la=a[i];
            }else{
                if(mid==0){
                    f=0;break;
                }
                for(auto e:ma){
                    if(e.fi>=-a[i])break;
                    ma.erase(e.fi);
                }
                ll now=1;
                ll z=-a[i];
                while(now==1){
                    if(ma[z]==mid&&z<0){
                        ma.erase(z);
                        z++;
                    }else{
                        ma[z]++;
                        now=0;
                    }
                }
                if(ma[0]>0){
                    f=0;
                    break;
                }
                la=a[i];
            }
        }
        if(f)ok=mid;
        else ng=mid;
    }
    cout<<ok+1<<endl;
}
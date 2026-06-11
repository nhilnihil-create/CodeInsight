#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const int inf=1e9+7;
const ll INF=1e18;
const int mod=998244353;

int main(){
    int a,b,q;cin>>a>>b>>q;
    vll s(a),t(b);
    rep(i,a)cin>>s[i];
    rep(i,b)cin>>t[i];
    vll ans(q,INF);
    ll x,sl,sr,sm,tl,tr,tm;
    rep(i,q){
        cin>>x;
        sl=-1;sr=a;
        while(sr-sl>1){
            sm=(sl+sr)/2;
            if(s[sm]<x)sl=sm;
            else sr=sm;
        }
        tl=-1;tr=b;
        while(tr-tl>1){
            tm=(tl+tr)/2;
            if(t[tm]<x)tl=tm;
            else tr=tm;
        }
        if(sl>-1&&tl>-1)ans[i]=x-min(s[sl],t[tl]);
        if(sl>-1&&tr<b)ans[i]=min(ans[i],t[tr]-s[sl]+min(t[tr]-x,x-s[sl]));
        if(sr<a&&tl>-1)ans[i]=min(ans[i],s[sr]-t[tl]+min(s[sr]-x,x-t[tl]));
        if(sr<a&&tr<b)ans[i]=min(ans[i],max(s[sr],t[tr])-x);
    }
    rep(i,q)cout<<ans[i]<<endl;
}
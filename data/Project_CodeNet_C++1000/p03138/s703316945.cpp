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
const ll inf=1e9+7;
const ll INF=1e18;

int main(){
    ll n,k;cin>>n>>k;
    vll a(n);rep(i,n)cin>>a[i];
    bitset<40> K(k);
    bitset<40> ans(0);
    int zero,one;
    bool less=false;
    for(int i=39;i>=0;i--){
        if(!less&&!K.test(i))continue;
        zero=0;one=0;
        rep(j,n){
            bitset<40> tmp(a[j]);
            if(tmp.test(i))one++;
            else zero++;
        }
        if(!less&&zero<=one&&K.test(i))less=true;
        else if(one<zero&&(less||K.test(i)))ans.set(i);
    }
    ll Ans=0;ll res=1;
    rep(i,40){
        Ans+=ans[i]*res;
        res*=2;
    }
    ll fx=0;
    rep(i,n)fx+=Ans^a[i];
    cout<<fx<<endl;
}
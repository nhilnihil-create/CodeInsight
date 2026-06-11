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
    ll n,m;cin>>n>>m;
    vin a(n);
    rep(i,n){
        cin>>a[i];
        a[i]%=m;
    }
    vll b(n+1);//b[i]:先頭i個の和
    map<ll,ll> r;
    b[0]=0;
    r[0]++;
    rep(i,n){
        b[i+1]=a[i]+b[i];
        b[i+1]%=m;
        r[b[i+1]]++;
    }
    ll sum=0;ll tmp;
    for (auto p=r.begin();p!=r.end();p++){
        tmp=p->second;
        sum+=tmp*(tmp-1)/2;
    }
    cout<<sum<<endl;
}
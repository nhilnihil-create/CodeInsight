#define _GLIBCXX_DEBUG
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

int main(){
    int n;cin>>n;
    vin a(n);rep(i,n)cin>>a[i];
    vin len(n+1),omit(n);
    len[0]=abs(a[0]);len[n]=abs(a[n-1]);
    rep(i,n-1)len[i+1]=abs(a[i+1]-a[i]);
    omit[0]=abs(a[1]);omit[n-1]=abs(a[n-2]);
    rep2(i,1,n-1)omit[i]=abs(a[i+1]-a[i-1]);
    int sum=0;
    rep(i,n+1)sum+=len[i];
    rep(i,n)cout<<sum-len[i]-len[i+1]+omit[i]<<endl;
}
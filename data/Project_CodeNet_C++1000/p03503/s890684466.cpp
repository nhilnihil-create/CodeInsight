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
    vvin f(n,vin(10));
    vvin p(n,vin(11));
    rep(i,n)rep(j,10)cin>>f[i][j];
    rep(i,n)rep(j,11)cin>>p[i][j];
    int res;
    ll sum;
    ll M=-INF;
    rep2(i,1,1<<10){
        bitset<12> tmp(i);
        sum=0;
        rep(j,n){
            res=0;
            rep(k,10){
                if(tmp.test(k)&&f[j][k])res++;
            }
            sum+=(ll)p[j][res];
        }
        M=max(M,sum);
    }
    cout<<M<<endl;
}
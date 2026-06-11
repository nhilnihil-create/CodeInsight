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
    string s;cin>>s;
    int n=s.size();
    vll a(n+1),ab(n+1),abc(n+1);
    ll res=1;//res=3^(そこまでの?の数)=そこまでの文字列の場合の数
    rep(i,n){
        a[i+1]=a[i];
        if(s[i]=='?')a[i+1]*=3;
        if(s[i]=='A'||s[i]=='?')a[i+1]+=res;
        a[i+1]%=inf;
        ab[i+1]=ab[i];
        if(s[i]=='?')ab[i+1]*=3;
        if(s[i]=='B'||s[i]=='?')ab[i+1]+=a[i];
        ab[i+1]%=inf;
        abc[i+1]=abc[i];
        if(s[i]=='?')abc[i+1]*=3;
        if(s[i]=='C'||s[i]=='?')abc[i+1]+=ab[i];
        abc[i+1]%=inf;
        if(s[i]=='?'){
            res*=3;
            res%=inf;
        }
    }
    cout<<abc[n]<<endl;
}
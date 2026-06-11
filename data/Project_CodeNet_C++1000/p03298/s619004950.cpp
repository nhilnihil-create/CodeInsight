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
    string s;cin>>s;
    string t=s.substr(n,n);reverse(all(t));
    s=s.substr(0,n);
    //cout<<s<<" "<<t<<endl;
    map<pair<string,string>,ll> a,b;
    rep(i,1<<n){
        bitset<20> tmp(i);
        string x,y,w,z;
        rep(j,n){
            if(tmp[j]){
                x+=s[j];
                w+=t[j];
            }
            else{
                y+=s[j];
                z+=t[j];
            }
        }
        a[mp(x,y)]++;
        b[mp(w,z)]++;
    }
    ll ans=(ll)0;
    for(auto c=a.begin();c!=a.end();c++){
        auto p=c->first;
        ans+=(c->second)*b[mp(p.second,p.first)];
    }
    cout<<ans<<endl;
}
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

map<int,int> pf;

void prime_factor(int n){
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            pf[i]++;
            n/=i;
        }
    }
    if(n!=1)pf[n]++;
    return;
}

int main(){
    int n;cin>>n;
    rep2(i,2,n+1)prime_factor(i);
    ll a=0;ll b=0;ll c=0;ll d=0;ll e=0;
    rep2(i,2,n+1){
        if(pf[i]>=74)a++;
        if(pf[i]>=24)b++;
        if(pf[i]>=14)c++;
        if(pf[i]>=4)d++;
        if(pf[i]>=2)e++;
    }
    ll ans=0;
    ans+=a+(b*e-b)+(c*d-c)+(e*d*(d-1)/2-d*(d-1));
    cout<<ans<<endl;
    /*cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<d<<endl;
    cout<<e<<endl;*/
}
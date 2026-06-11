// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで

#include <bits/stdc++.h>
#define mod 1000000007
#define INF 1001001001
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
using namespace std;

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b=0,d,n,maxi=0,f=0,mini=INF,sum=0;
    string str;
    char c;
    set<ll> s;
    map<ll,ll> m;
    cin>>n;
    rep(i,n){
        cin>>a;
        s.insert(a);
        m[a]++;
    }
    for(auto itr= s.begin();itr!=s.end();++itr){
        if(*itr<=m[*itr]){
            sum+=(m[*itr]-*itr);
        }else{
            sum+=m[*itr];
        }
    }
    cout<<sum<<endl;
    return 0;
}

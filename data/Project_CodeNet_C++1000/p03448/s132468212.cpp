// lcmとかはg++ -std=c++17 default.cppみたいなかんじで
//vector<vector<ll>> piyo(tate,vector<ll> (yoko));

#include <bits/stdc++.h>
#define mod 1000000007
#define INF 1000000000
#define ll long long
#define ln cout<<endl;
#define Yes cout<<"Yes"<<endl;
#define No cout<<"No"<<endl;
#define double long double
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
using namespace std;

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll maxi=0,f=0,mini=INF,sum=0;
    string str,str2;
    ll h,w;
    ll n,x;
    ll a,b,c,d;
    cin>>a>>b>>c>>x;
    REP(i,0,a+1)REP(j,0,b+1)REP(k,0,c+1){
        if(i*500+j*100+k*50==x) sum++;
    }
    cout<<sum<<endl;
    
    return 0;
}

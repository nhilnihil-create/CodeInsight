// lcmとかはg++ -std=c++17 default.cppみたいなかんじで
//vector<vector<ll>> piyo(tate,vector<ll> (yoko));

#include <bits/stdc++.h>
#define mod 1000000007
#define INF 1000000000
#define ll long long
#define ln cout<<endl;
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define double long double
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
using namespace std;
ll target;

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll maxi=0,f=0,mini=INF,sum=0;
    string str,str1,str2;
    ll i,h,w;
    ll n,x,m;
    ll a,b,d,c;
    set<string> s;
    cin>>a>>b>>x;
    for(i=a;i<=b;i++){
        if(a+x>i||b-x<i) cout<<i<<endl;
    }   


    return 0;
}

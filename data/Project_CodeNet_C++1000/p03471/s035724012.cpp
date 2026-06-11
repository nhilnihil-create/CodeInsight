// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで

#include <bits/stdc++.h>
#define mod 1000000007
#define INF LLONG_MAX
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
using namespace std;
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,d,n,maxi=0,f=0,mini=INF,sum=0;
    ll q;
    ll y;
    cin>>n>>y;
    REP(i,0,n+1)REP(j,0,n+1-i)REP(k,0,n+1-i-j){
        if(i*10000+j*5000+k*1000==y&&i+j+k==n){
            cout<<i<<" "<<j<<" "<<k<<endl;
            return 0;
        }
    }
    cout<<"-1 -1 -1"<<endl;
    return 0;
}

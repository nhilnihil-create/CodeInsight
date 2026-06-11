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

    ll a,b,c,d,n,maxi=0,f=0,mini=INF,sum=0;
    cin>>n;
    ll la=0,lb=0,lc=0;
    rep(i,n){
        cin>>a>>b>>c;
        if(a-la>=abs(b-lb)+abs(c-lc)&&(a-la)%2==(abs(b-lb)+abs(c-lc))%2){

        }else{
            f=1;
        }
        la=a;lb=b;lc=c;
    }
    if(f==1) No;
    else Yes;
    
    return 0;
}

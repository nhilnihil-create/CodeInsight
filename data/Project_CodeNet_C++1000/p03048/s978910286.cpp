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
    cin>>a>>b>>c>>n;
    if(a<c) swap(a,c);
    if(a<b) swap(a,b);
    REP(i,0,3001){
        if(i*a>n) continue;
        if(i*a+b*(3000-i)+c*(3000-i)<n) continue;
        REP(j,0,3001-i){
            if(i*a+j*b>n) continue;
            REP(k,0,3001-i-j){
        if(a*i+b*j+c*k==n) {
            sum++;
            break;
        }
    }
        
    }    
    }
    cout<<sum<<endl;
    return 0;
}

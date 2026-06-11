#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

vector<int> seat;

int q(int x){
    cout<<x<<endl;
    string s;cin>>s;
    if(s=="Vacant") return INF;
    if(s=="Female") return -1;
    if(s=="Male")   return 1;
    else            return -INF;
}

void solve(int l,int r){
    if(l>=r) return;
    int m=(l+r)/2;
    int x=q(m);
    if(x==INF) return;
    seat[m]=x;

    bool lf=false,rf=false;
    //left
    if((m-l)%2==0){
        if(seat[m]!=seat[l]) lf=true;
    }
    else{
        if(seat[m]==seat[l]) lf=true;
    }
    if((r-m)%2==0){
        if(seat[r]!=seat[m]) rf=true;
    }
    else{
        if(seat[r]==seat[m]) rf=true;
    }
    if(lf){
        solve(l,m);
    }
    else if(rf){
        solve(m,r);
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n;cin>>n;
    //1->male -1->female
    seat=vector<int>(n,0);

    seat[0]=q(0);
    if(seat[0]==INF) return 0;
    seat[n-1]=q(n-1);
    if(seat[n-1]==INF) return 0;

    solve(0,n-1);
    return 0;
}

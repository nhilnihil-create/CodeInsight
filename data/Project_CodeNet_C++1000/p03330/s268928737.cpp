#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair< ll, ll > Pi;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
const ll INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()
#define mp make_pair
bool compare(Pi a, Pi b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}


bool In_map(ll y,ll x,ll h,ll w){
    if(y<0 || x<0 || y>=h || x>=w){
        return 0;
    }else{
        return 1;
    }
}
const vector<ll> d0{0,0,1,1,2,2};
const vector<ll> d1{1,2,0,2,0,1};
const vector<ll> d2{2,1,2,0,1,0};

int main() {
    ll N,C;
    cin >>N>>C;

    vector<vector<ll>>D(C,vector<ll>(C));
    vector<vector<ll>>c(N,vector<ll>(N));
    vector<vector<ll>>D2(C,vector<ll>(3,INF));
    vector<vector<ll>>E(3,vector<ll>(C));
    rep(i,C){
        rep(j,C){
            cin>>D[i][j];
        }
    }

    rep(i,N){
        rep(j,N){
            cin>>c[i][j];
            c[i][j]--;
            E[(i+j)%3][c[i][j]]++;
        }
    }
    /*rep(i,C){
        rep(j,C){
            chmin(D2[i][j%3],D[i][j]);
        }
    }*/
    ll ans = INF;
    rep(c0,C)rep(c1,C)rep(c2,C){
        if(c0==c1 || c0==c2 || c1==c2)continue;
        ll now=0;
        rep(i,C){
            now+=E[0][i]*D[i][c0]+E[1][i]*D[i][c1]+E[2][i]*D[i][c2];
        }

        
        
        chmin(ans,now);
    }


    cout << ans << endl;


    return 0;
    

}
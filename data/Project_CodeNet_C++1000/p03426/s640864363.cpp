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
const vector<ll> dx{1,0,-1,0};
const vector<ll> dy{0,1,0,-1};


int main() {
    ll H,W,D;
    cin >>H>>W>>D;
    vector<Pi>pos(H*W);

    rep(i,H){
        rep(j,W){
            ll a;
            cin>>a;
            a--;
            pos[a]=mp(i,j);
        }
    }
    vector<vector<ll>>sum(D,vector<ll>((H*W)/D + 2));
    rep(i,D){
        rep(j,(H*W)/D + 10){
            ll now=i+D*j;
            ll next=i+D*(j+1);
            //cout<<next<<endl;
            if(next>=H*W)break;
            ll x=pos[now].second;
            ll y=pos[now].first;
            ll nx=pos[next].second;
            ll ny=pos[next].first;
            sum[i][j+1]=sum[i][j]+abs(nx-x)+abs(ny-y);
            //cout<<sum[i][j+1]<<" ";
        }
        //cout<<endl;
    }

    ll Q;
    cin>>Q;
    rep(i,Q){
        ll l,r;
        cin>>l>>r;
        l--,r--;
        ll inx=l%D;
        ll ans=sum[inx][r/D]-sum[inx][l/D];
        cout<<ans<<endl;
    }



    return 0;
    

}
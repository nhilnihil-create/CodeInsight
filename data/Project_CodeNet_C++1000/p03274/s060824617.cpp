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
    ll N,K;
    cin >>N>>K;
    vector<ll>x1;
    vector<ll>x2;

    rep(i,N){
        ll x;
        cin>>x;
        if(x>0){
            x1.pb(x);
        }else{
            x2.pb(-x);
        }
    }

    sort(all(x1));
    sort(all(x2));
    ll N1 = x1.size();
    ll N2 = x2.size();
    ll  ans = INF;
    if(N2==0){
        cout<<x1[K-1]<<endl;
        return 0;
    }
    rep(i,N-K+1){
        ll l,r;
        l = x2.size()-i-1;
        r = K-l-2;
        //cout<<r<<endl;
        if(r<0){
            chmin(ans,x2[l]);
        }else{
            chmin(ans,x2[l]+x1[r]+min(x2[l],x1[r]));
        }

    }


    cout << ans << endl;


    return 0;
    

}
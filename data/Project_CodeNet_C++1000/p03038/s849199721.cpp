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
    if(a.second != b.second){
        return a.second > b.second;
        
    }else{
        return a.first < b.first;
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
    ll N,M;
    cin >>N>>M;
    vector<ll>A;
    rep(i,N){
        ll a;
        cin>>a;
        A.pb(a);
    }
    vector<Pi>BC(M);
    rep(i,M){
        ll b,c;
        cin>>b>>c;
        BC[i]=mp(b,c);
    }

    sort(all(A));
    reverse(all(A));
    sort(all(BC),compare);

    ll ans = 0;
    ll cntA=0,cntB=0;
    rep(i,N){
        ll a,b;
        if(cntA<N){
            a=A[cntA];
        }else{
            a=0;
        }
        if(cntB<M){
           b=BC[cntB].second;
        }else{
            b=0;
        }
 
        if(a>b){
            ans+=a;
            cntA++;
        }else{
            ans+=b;
            if(BC[cntB].first==1){
                cntB++;
            }else{
                BC[cntB].first--;
            }
        }
    }
    cout << ans << endl;


    return 0;
    

}
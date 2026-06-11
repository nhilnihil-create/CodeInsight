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
    ll N,C;
    cin >>N>>C;
    vector<ll>imo(100005);
    map<Pi,bool>m;
    vector<tuple<ll,ll,ll>>tp(N);
    rep(i,N){
        ll s,t,c;
        cin>>s>>t>>c;
        tp[i]=make_tuple(s,t,c);
        
    }
    sort(all(tp));
    rep(i,N){
        ll s,t,c;
        s=get<0>(tp[i]);
        t=get<1>(tp[i]);
        c=get<2>(tp[i]);
        if(m[mp(s,c)]==1){
            imo[s+1]++;
            imo[t+1]--;
        }else{
            imo[s]++;
            imo[t+1]--;
        }
        m[mp(t,c)]=1;
    }
    ll ans=0;
    rep(i,100003){
        imo[i+1]+=imo[i];
    }

    rep(i,100004){
        chmax(ans,imo[i]);
    }

    cout << ans << endl;


    return 0;
    

}
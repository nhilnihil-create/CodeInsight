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
    int N,K;
    cin >>N>>K;
    vector<ll>v(N);
    deque<ll> d;
    deque<ll> d2;
    rep(i,N){
        cin>>v[i];
        d.pb(v[i]);
    }
    
    ll ans = 0;
    d2 = d;
    
    rep(i,min(N,K)+1){
        
        rep(j,min(N,K)-i+1){
            //cout<<i<<" "<<j<<endl;
            vector<ll>have;
            d=d2;
            ll now=0;
            rep(k,i){
                now += d.front();
                have.pb(d.front());
                d.pop_front();
            }
            rep(k,j){
                now += d.back();
                have.pb(d.back());
                d.pop_back();
            }
            sort(all(have));
            int size = have.size();
            rep(k,min(K-i-j,size)){
                if(have[k]<0){
                    now+=-have[k];
                }else{
                    break;
                }
            }
            //cout<<now<<endl;
            chmax(ans,now);
        }
    }
    cout << ans << endl;


    return 0;
    

}
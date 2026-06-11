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

ll N=55555*5;
vector<bool> isp(N+1, true);

void sieve() {
  isp[0] = false;
  isp[1] = false;
  for (int i=2; pow(i,2)<=N; i++) {
    if (isp[i]) for(int j=2; i*j<=N; j++) isp[i*j] = false;
  }
}
int main() {
    sieve();
    ll M;
    cin >>M;
    vector<ll>p;
    rep(i,55556){
        if(isp[i]){
            if(i%5==1)
                p.pb(i);
            
        }
    }
    rep(i,M){
        cout<<p[i]<<" ";
    }

    cout  << endl;


    return 0;
    

}
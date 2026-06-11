#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair< ll, ll > Pi;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(i,n) for(ll i=1;i<=(n);i++)
#define rep3(i,i0,n) for(ll i=i0;i<(n);i++)
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
    ll N;
    cin >>N;
    vector<ll>A(N);
    vector<ll>B(N);
    ll sum=0;
    rep(i,N){
        cin>>A[i];
        B[i]=A[i]-i-1;
    }
    sort(all(B));
    ll ans1 = 0;
    ll b1 = B[N/2];
    rep(i,N){
        ans1+=abs(A[i]-b1-i-1);
    }
    

    cout << ans1 << endl;


    return 0;
    

}
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
    
    vector<ll>A(N);

    ll inx;
    rep(i,N){
        cin>>A[i];
        if(A[i]==1){
            inx=i;
        }
    }

    ll L1 = N-1;
    /*if(inx==0 || inx == N-1){
        L1--;
    }*/
    ll L2 = N-inx-1;
    ll ans=0;
    if(L1%(K-1)==0){
        ans+=L1/(K-1);
    }else{
        ans+=L1/(K-1)+1;
    }
    /*if(L2%(K-1)==0){
        ans+=L2/(K-1);
    }else{
        ans+=L2/(K-1)+1;
    }*/

    cout << ans << endl;


    return 0;
    

}
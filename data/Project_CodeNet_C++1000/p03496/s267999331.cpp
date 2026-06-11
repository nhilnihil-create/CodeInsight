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
    ll N;
    cin >>N;
    vector<ll>A(N);
    ll nm=0;
    ll pm=0;
    ll pinx;
    ll ninx;
    rep(i,N){
        cin>>A[i];
        if(A[i]>pm){
            pm=A[i];
            pinx=i;
        }
        if(A[i]<nm){
            nm=A[i];
            ninx=i;
        }

    }
    vector<Pi>ans;
    if(pm>-nm){
        
        rep(i,N){
            if(A[i]<0){
                A[i]+=pm;
                ans.pb(mp(pinx,i));
            }
        }
        //A[0]+=pm;
        if(pinx!=0)
            ans.pb(mp(pinx,0));
        rep(i,N-1){
            ans.pb(mp(i,i+1));
        }
    }else{
        rep(i,N){
            if(A[i]>0){
                A[i]+=nm;
                ans.pb(mp(ninx,i));
            }
        }
        if(ninx!=N-1)
            ans.pb(mp(ninx,N-1));
        rep(i,N-1){
            ans.pb(mp(N-i-1,N-i-2));
        }
    }
    ll M=ans.size();
    cout<<M<<endl;
    rep(i,M){
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
    }



    return 0;
    

}
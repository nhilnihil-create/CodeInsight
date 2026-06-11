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
    vector<ll> A(N);
    ll mx=0;
    vector<ll> BT(50);
    rep(i,N){
        ll a;
        cin>>a;
        A[i] = a;
        rep(j,50){
            if(((ll(1)<<(j))&a) != 0){
                //cout<<j<<endl;
                BT[j]++;
            }
        }

    }
    /*rep(i,50){
        cout<<BT[i]<<endl;
    }*/
    ll X=0;
   
    vector<bool> BK;
    ll B=0;
    ll flag = 0;
    rep(i,50){
        if((ll(1)<<(49-i)) & K){
            flag = 1;
        }
        if(flag == 1){
            if((ll(1)<<(49-i)) & K){
                BK.pb(1);
            }else{
                BK.pb(0);
            }
            
        }else{
            //cout << bitset<50>(B)<<endl;
            B += (ll(1)<<(49-i));
        }
    }
    
    ll M = BK.size();
    //reverse(all(BK));
    vector<vector<ll>> dp(M+1,vector<ll>(2));
    rep(i,M){
        ll a,b,c,d;
        a = dp[i][0]+BT[M-1-i]*(ll(1)<<(M-1-i));
        b = dp[i][0]+(N-BT[M-1-i])*(ll(1)<<(M-1-i));
        c = dp[i][1]+BT[M-1-i]*(ll(1)<<(M-1-i));
        d = dp[i][1]+(N-BT[M-1-i])*(ll(1)<<(M-1-i));
        if(i==0){

            dp[i+1][0] = a;
            dp[i+1][1] = max(a,b);
     
        }else{
            if(BK[i]==1){
                dp[i+1][0] = max({a,b,c});
                dp[i+1][1] = d;
            }else{
                dp[i+1][0] = max({a,b});
                dp[i+1][1] = c;
            }
        }
        
        //cout<<dp[i+1][0]<<" "<<dp[i+1][1]<<endl;
    }
    
    ll ans = max(dp[M][0],dp[M][1]);
    //cout<<ans<<endl;
    //cout << bitset<50>(B)<<" "<<bitset<50>(A[0]);
    rep(i,N){
        ans += (B&A[i]);
        //cout<<(B&A[i])<<endl;
    }

    cout << ans << endl;


    return 0;
    

}
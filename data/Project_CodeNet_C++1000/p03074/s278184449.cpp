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
    string S;
    cin >>N>>K>>S;
    if(N==1){
        cout<<1<<endl;
        return 0;
    }
    vector<ll> P;
    ll cnt=0;
    char now=S[0];
    rep(i,N){
        if(S[i] ==  now){
            cnt++;
            if(i==N-1){
                P.pb(cnt);
            }
        }else{
            P.pb(cnt);
            cnt = 1;
        }
        now = S[i];
    }
    
    ll ans=0;

    if(S[0] == '0'){
        P.insert(P.begin(),0);
    }
    if(S[N-1] == '0'){
        P.pb(0);
    }
    
   
 
        rep(i,K*2+1){
            if(i>= P.size()){
                cout<<ans<<endl;
                return 0;
            }
            ans+=P[i];
        }
        ll tmp = ans;
        ll k=0;
        while(1){
            if(2*k+2*K+2>= P.size()){
                cout<<ans<<endl;
                return 0;
            }
            tmp+= -P[2*k]-P[2*k+1]+P[2*k+2*K+1]+P[2*k+2*K+2];
            chmax(ans,tmp);
            k++;
        }
    

    
    cout << ans << endl;


    return 0;
    

}
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

int ctoi(const char c){
  if('0' <= c && c <= '9') return (c-'0');
  return -1;
}
int main() {
    string S;
    cin >>S;
    vector<ll> N(S.size());
    rep(i,S.size()){
        N[i] = ctoi(S[i]);
    }
    vector<vector<vector<ll>>> dp(N.size()+1,vector<vector<ll>>(8,vector<ll>(2)));
    vector<vector<vector<ll>>> dp2(N.size()+1,vector<vector<ll>>(8,vector<ll>(2)));
    dp2[0][0][0] = 1;
    rep(i,N.size()){
        rep(j,8){
            rep(k,2){
                for(int x=0;x<=(k ? 9 : N[i]); x++){
                    if(x==3){
                        dp[i+1][(j|1)][k || (x<N[i])] += dp[i][j][k];
                        dp[i+1][(j|1)][k || (x<N[i])] += dp2[i][j][k];
                    }else if(x==5){
                        dp[i+1][(j|2)][k || (x<N[i])] += dp[i][j][k];
                        dp[i+1][(j|2)][k || (x<N[i])] += dp2[i][j][k];
                    }else if(x==7){
                        dp[i+1][(j|4)][k || (x<N[i])] += dp[i][j][k];
                        dp[i+1][(j|4)][k || (x<N[i])] += dp2[i][j][k];
                    }else if(x==0){
                        dp2[i+1][j][k || (x<N[i])] += dp2[i][j][k];
                    }
                }
            }
        }
    } 
    /*rep(i,N.size()+1){
        rep(j,8){
            cout<<dp[i][j][1]<<" ";
        }
        cout<<endl;
    }
    rep(i,N.size()+1){
        rep(j,8){
            cout<<dp[i][j][0]<<" ";
        }
        cout<<endl;
    }*/
    cout << dp[N.size()][7][0]+dp[N.size()][7][1]<<endl;
   


    return 0;
    

}
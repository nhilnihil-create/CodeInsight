#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n);i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a,ll b){return(a%b)?gcd(b,a%b):b;}
ll lcm(ll a,ll b){return(a*b/gcd(a,b));}
const ll INF=1LL<<60;

int n;
vector<int> h(110);

int main(){
    cin>>n;
    rep(i,0,n) cin>>h[i];
    int cnt=0;
    int x=0;
    int ans=0;
    while(cnt!=n){
        cnt=0;
        rep(i,0,n){
            if(h[i]!=0){
                h[i]--;
                x++;
                if(i==n-1){
                    ans++;
                    x=0;
                }
            }
            else if(h[i]==0){
                if(x!=0) ans++;
                x=0;
                cnt++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}

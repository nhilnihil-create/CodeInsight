#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

int main(){
    int n,k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> cum(n+1,0);
    rep(i,n) cum[i+1]=a[i];
    rep(i,n) cum[i+1]+=cum[i];
    vector<ll> b;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            b.push_back(cum[j]-cum[i]);
        }
    }
    vector<bool> unuse((int)b.size(),false);

    for(int bit=43;bit>=0;bit--){
        int c = 0;
        rep(i,b.size()){
            if(unuse[i]) continue;
            if(b[i]>>bit&1) ++c;
        }
        if(c>=k){
            rep(i,b.size()){
                if(unuse[i]) continue;
                if(!(b[i]>>bit&1)) unuse[i]=true;
            }
        }
    }

    int c = 0;
    ll ans = 0;
    rep(i,b.size()){
        if(unuse[i]) continue;
        else{
            if(c==0){
                ans = b[i];
                ++c;
            }else{
                ans = ans & b[i];
                ++c;
                if(c==k) break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
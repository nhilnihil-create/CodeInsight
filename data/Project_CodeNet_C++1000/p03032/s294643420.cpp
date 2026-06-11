#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
const ll mod = 1000000007;
const ll INF = 1e+14;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG

int main(){
    int n,K;
    cin>>n>>K;
    vector<ll> v;
    rep(i,n){
        ll a;
        cin>>a;
        v.push_back(a);
    }
    ll ans=0;
    vector<ll> onway;
    rep(i,n+1){   //iが取り出す数
        if(i>K) break;
        rep(j,i+1){
            rep(k,j){
                onway.push_back(v[k]);
            }
            for(int k=n-1; k>=n-(i-j); k--){
                onway.push_back(v[k]);
            }
            if(!onway.empty()){
                sort(onway.begin(),onway.end());
                rep(k,K-i){ //中に入れる
                    if(onway[k]>=0) break;
                    else onway[k]=0;
                }
                ll sum=0;
                rep(k,i){
                    sum+=onway[k];
                }
                ans=max(ans,sum);
            
                onway.clear();
            }
        }
    }
    cout<<ans<<endl;
}
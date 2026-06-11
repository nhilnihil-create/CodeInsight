#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<(n);i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;

int main(){
    int n,k;cin>>n>>k;
    vi v(n+1);
    rep(i,n)cin>>v[i+1];
    ll ans = 0;
    rep(i,n+1){
        rep2(j,i+1,n+2){
            ll sum =0;
            vi t;
            if(j==n+1){
                if(i>k)continue;
                rep(a,i){
                    t.push_back(v[a+1]);
                }
                sort(been(t));
                int l =t.size();
            rep(a,min(l,k-l)){
                if(t[0]>0)break;
                t.erase(t.begin());
            }
            rep(a,t.size())sum+=t[a];
            ans=max(ans,sum);
            continue;
            }
            if(n-j+i+1>k)continue;
            
            rep(a,i){
                t.push_back(v[a+1]);
            }
            rep(a,n-j+1){
                t.push_back(v[n-a]);
            }
            sort(been(t));
            int l =t.size();
            rep(a,min(l,k-l)){
                if(t[0]>0)break;
                t.erase(t.begin());
            }
            rep(a,t.size())sum+=t[a];
            ans=max(ans,sum);
        }
    }
    cout<<ans<<endl;
    
}
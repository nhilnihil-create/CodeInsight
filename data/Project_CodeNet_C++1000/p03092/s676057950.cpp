#include <bits/stdc++.h>
#define rep(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define rer(i, a, b) for(ll i = ll(a) - 1; i >= ll(b); i--)
#define sz(v) (int)(v).size()
#define pb push_back
#define sc second
#define fr first
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
using namespace std;
typedef long long int ll;
typedef pair <int, int> P;

const ll MOD=1000000007;
int N;
ll A,B;
int p[5000];
ll dp[5000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>A>>B;
    rep(i,0,N){
        cin>>p[i];
        p[i]--;
    }
    rep(i,0,N){
        bool t=false;
        int cnt=0;
        int u;
        rep(j,0,N){
            if(p[j]>i&&j>0){
                dp[j]=dp[j-1];
            }
            if(t&&p[j]<i){
                cnt++;
                dp[j]=min(A+dp[j], B*cnt+dp[u]);
            }
            if(p[j]==i){
                u=j;
                t=true;
            }
        }
    }
    cout <<dp[N-1]<<"\n";
}
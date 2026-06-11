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
ll N;
vector<ll> A,B;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    A.resize(N); B.resize(N);
    bool t=false;
    ll res=-1;
    ll sum=0;
    rep(i,0,N){
        cin>>A[i]>>B[i];
        sum+=A[i];
        if(A[i]>B[i]){
            t=true;
            if(res==-1){
                res=i;
            }
            else if(B[i]<B[res]){
                res=i;
            }
        }
    }
    if(t) cout <<sum-B[res]<<"\n";
    else cout <<0<<"\n";
}
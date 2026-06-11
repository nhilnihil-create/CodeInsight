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
    int n,m;cin>>n>>m;
    vector<P> s;
    rep(i,n){
        int a,b;cin>>a>>b;
        s.push_back({a,b});
    }
    sort(been(s));
    ll ans =0,i =0,nw=0;
    while(nw<m){
        ll v =s[i].first,c= s[i].second;
        if(nw+c>m){
            ans += (m-nw)*v;
            nw = m;
        }
        else{
            ans+=c*v;
            nw+=c;
        }
        i++;
    }
    cout<<ans<<endl;
}
#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
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
const double PI = acos(-1);
int main(){
    int n;cin>>n;
    vector<P>res;
    vector<P> ans;
    if(n%2){
        n--;
        rep(i,n)ans.push_back({n+1,i+1});
    }
    int want =1+n;
    rep(i,n){
        rep2(j,i+1,n){
            if(i+1+j+1==want)continue;
            ans.push_back({i+1,j+1});
        }
    }
    cout<<ans.size()<<endl;
    rep(i,ans.size()){
        cout<<ans[i].first<<' '<<ans[i].second<<endl;
    }
}
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
    ll n;
    cin>>n;
    vl ress;
    ll ans =0;
    for(ll i = 1;i<=sqrt(n)+1;i++){
        if(n%i==0){
            ress.push_back(i-1);
            ress.push_back(n/i-1);
        }
    }
    rep(i,ress.size()){
        if(ress[i]==0)continue;
        if(n%ress[i]==n/ress[i])ans+=ress[i];
    }
    cout<<ans<<endl;
}
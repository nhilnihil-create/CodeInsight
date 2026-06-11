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
	ll n;cin>>n;
    rep(i,3600){
        if(i==0)continue;
        rep(j,3600){
            if(j==0)continue;
            ll mo = 4*i*j-n*i-n*j,ki=n*i*j;
            if(mo>0&&ki%mo==0){
                cout<<i<<' '<<j<<' '<<ki/mo<<endl;
                return 0;
            }
        }
    }
}
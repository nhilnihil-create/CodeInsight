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
    vector<pair<ll,int>>sum;
    vi a(n),b(n);
    rep(i,n){
        cin>>a[i]>>b[i];
        sum.push_back({a[i]+b[i],i});
    }
    sort(been(sum));
    ll aok =0,tkh=0;
    rep(i,n){
        if(i%2==0){
            tkh+=a[sum[n-1-i].second];
        }
        else{
            aok+=b[sum[n-1-i].second];
        }
    }
    cout<<tkh-aok<<endl;
}
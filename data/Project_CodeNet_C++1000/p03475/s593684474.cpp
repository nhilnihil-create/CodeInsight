#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
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
    int n;cin>>n;
    int c[n-1],s[n-1],f[n-1];
    rep(i,n-1)cin>>c[i]>>s[i]>>f[i];
    rep(a,n){
        int res =0;
        rep2(i,a,n-1){
            if(res>s[i]){
                res=ceil((double)res/(double)f[i])*f[i];
            }
            else{
                res = s[i];
            }
            res+=c[i];
        }
        cout<<res<<endl;
    }
    
    }
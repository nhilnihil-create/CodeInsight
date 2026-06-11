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
    int n;
    cin>>n;
    int f[n][10],p[n][11];
    rep(i,n){
        rep(j,10){
            cin>>f[i][j];
        }
    }
    rep(i,n){
        rep(j,11){
            cin>>p[i][j];
        }
    }
    int ans =-INF;
    rep(bit,(1<<10)){
        if(bit==0)continue;
        vi cnt(n,0);
        rep(i,10){
            if(bit&(1<<i)){
                rep(j,n){
                    if(f[j][i]==1)cnt[j]++;
                }
            }
        }
        int sum=0;
        rep(i,n){
            sum+=p[i][cnt[i]];
        }
        //cout<<sum<<' '<<bit<<endl;
        ans =max(ans,sum);
    }
    cout<<ans<<endl;
    }
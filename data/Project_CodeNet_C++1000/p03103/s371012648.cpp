#include "bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define all(a) a.begin(),a.end()
typedef pair<int,int> P;
const long long mod=1000000007;
const long long inf=1ll<<61;

int a[100006],b[100006];
P ab[100006];

signed main(){
    int n,m;cin>>n>>m;
    rep(i,n){
        cin>>a[i]>>b[i];
        ab[i]=P(a[i],b[i]);
    }
    sort(ab,ab+n);
    int ans=0,rs=0;
    rep(i,n){
        if(rs+ab[i].second<m){
            ans+=ab[i].first*ab[i].second;
            rs+=ab[i].second;
        }
        else{
            ans+=ab[i].first*(m-rs);
            break;
        }
    }
    cout<<ans<<endl;
}
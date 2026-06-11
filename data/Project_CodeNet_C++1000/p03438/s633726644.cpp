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
    int n,q;cin>>n;
    int a[n],b[n];
    ll am =0,bm=0;
    rep(i,n){
        cin>>a[i];
        am+=a[i];
    }
    rep(i,n){
        cin>>b[i];
        bm+=b[i];
    }
    ll d =bm-am;
    ll an=0,bn=0;
    rep(i,n){
        if(b[i]>a[i]){
            an+=((b[i]-a[i])/2)+((a[i]-b[i])%2?1:0);
        }
        else if(a[i]>b[i]){
            bn+=(a[i]-b[i]);
        }
    }
    if(an<=d&&bn<=d)cout<<"Yes"<<endl;
    else
    {
        cout<<"No"<<endl;
    }
    
}
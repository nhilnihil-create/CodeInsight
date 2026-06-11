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
    vi a(n);
    rep(i,n){
        int x;
        cin>>x;
        x-=(i+1);
        a[i]=x;
    }

    sort(been(a));

    ll ans=0;
    int b;
    if(n%2==0){
        b=(a[n/2-1]+a[n/2])/2;
    }
    else {
        b=a[(n+1)/2-1];
    }
    
    rep(i,n){
        ans+=abs(a[i]-b);
    }
    cout<<ans<<endl;
}

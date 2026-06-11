#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n;
    cin>>n;
    int a[n],b[n];
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];
    ll cnt=0;
    rep(i,n){
        if(a[i]<b[i]) cnt+=(b[i]-a[i])/2;
        else cnt-=a[i]-b[i];
    }
    if(cnt<0) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}
    



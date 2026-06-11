#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

ll gcd(ll x,ll y) {return y ? gcd(y,x%y) : x;}
ll lcm(ll x, ll y) {return x/gcd(x,y)*y;}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    int l[n],r[n];

    l[0]=a[0];
    for(int i=1;i<n;i++){
        l[i]=gcd(l[i-1],a[i]);
    } 
    reverse(all(a));
    r[0]=a[0];
    for(int i=1;i<n;i++) r[i]=gcd(r[i-1],a[i]);

    int ans=0;
    rep(i,n){
        int tmp;
        if(i==0){
            tmp=r[n-2];
        }
        else if(i==n-1){
            tmp=l[n-2];
        }
        else{
            tmp=gcd(l[i-1],r[n-2-i]);
        }
        ans=max(ans,tmp);
    }

    cout<<ans<<endl;
}

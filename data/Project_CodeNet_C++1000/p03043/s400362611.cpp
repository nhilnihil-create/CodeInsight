#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;
 
int main(){
    ll n,k;
    cin>>n>>k;
 
    long double ans=0;
    for(int i=1;i<=n;i++){
        int x=i;
        long double cnt=0;
        while(x<k){
            x*=2;
            cnt++;
        }
        long double tmp=1/pow(2,cnt);
        tmp/=(long double)n;
        ans+=tmp;
    }
 
    cout<<fixed<<setprecision(10)<<ans<<endl;
}
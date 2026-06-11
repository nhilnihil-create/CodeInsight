#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n,k;
    cin>>n>>k;

    long double ans=0;
    for(int i=1;i<=n;i++){
        int x=0;
        int tmp=i;
        long double xx=1;
        while(tmp<k){
            x++;
            tmp*=2;
            xx/=(long double)2;
        }
        ans+=xx;
    }
    ans/=(long double)n;

    cout<<fixed<<setprecision(12)<<ans<<endl;
}


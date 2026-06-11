#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n,k;
    cin >> n >> k;
    int a,b;
    double ans=0,ans2=0;
    //ans=(n-k+1)/double(n);

    rep(i,n){
        a=0;
        b=i+1;
        while(b<k){
            ++a;
            b*=2;
        }
        ans2+=pow(0.5,a)/double(n);
    }

    ans+=ans2/double(n);

    //cout << ans << endl;

    printf("%.10f",ans2);
    

    return 0;
}
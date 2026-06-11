#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;


int main(){
    fast_io

    int r, g, b, n;
    cin>>r>>g>>b>>n;
    int ans=0;
    for(int R=0;R<=n;R++){
        for(int G=0;G<=n;G++){
            int B=(n-r*R-g*G);
            if(B>=0 && B%b==0) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

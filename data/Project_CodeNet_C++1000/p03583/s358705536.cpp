#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main() {
    ll N;
    cin>>N;
    for(ll h=1;h<=3500;h++){
        for(ll n=1;n<=3500;n++){

            ll up=N*h*n;
            ll dow=4LL*h*n-N*n-N*h;
            if(dow==0) continue;
            if(up%dow!=0) continue;
            ll w=up/dow;
            if(0<w && w<=3500){
                cout<<h<<" "<<n<<" "<<w<<endl;
                return 0;
            }
        }
    }
}
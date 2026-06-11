#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    ll N;cin>>N;
    for(ll h=1;h<=3500ll;h++){
        for(ll n=1;n<=3500ll;n++){
            ll dem = (4*h*n - N*n - N*h);
            ll num = (N*h*n);

            if(dem==0 || num%dem)continue;
            ll w = num/dem;
            if(w>0)return cout<<h<<" "<<n<<" "<<w , 0;
        }
    }
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    ll N;
    cin>>N;
    
    for(ll h=1;h<=3500;h++){
        for(ll n=1;n<=3500;n++){
            ll tmp1=4*h*n-N*n-N*h;
            ll tmp2=N*h*n;

            if(tmp1<=0) continue;
            if(tmp2%tmp1==0){
                cout<<h<<" "<<n<<" "<<tmp2/tmp1<<endl;
                return 0;
            }
        }
    }
}
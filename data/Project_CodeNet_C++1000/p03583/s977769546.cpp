#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main() {
    ll N;
    cin>>N;

    for(int h=1;h<=3500;h++){
        for(int n=1;n<=3500;n++){
            
            ll x=N*h*n;
            ll y=4*h*n-N*h-N*n;
            if(y==0) continue;
            if(x%y!=0) continue;

            ll w=x/y;
            if(1<=w && w<=3500){
                cout<<h<<" "<<n<<" "<<w<<endl;
                return 0;
            }
            
        }
    }



}


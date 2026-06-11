#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
ll n;
int main(void){
    cin>>n;
    for(int i=1;i<=3500;i++){
        for(int j=1;j<=3500;j++){
            if((4*i*j-n*i-n*j)>0){
                if((n*i*j)%(4*i*j-n*i-n*j)==0){
                    cout<<i<<" "<<j<<" "<<(n*i*j)/(4*i*j-n*i-n*j)<<endl;
                    return 0;
                }
            }
        }
    }
    
}

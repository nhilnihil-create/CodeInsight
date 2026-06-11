#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    ll N;
    cin>>N;
    for(ll a = 1;a<=3500;a++){
        for(ll b = 1;b<=3500;b++){
            if(4*a*b-N*(a+b) <= 0) continue;
            if((N*a*b)%(4*a*b-N*(a+b)) == 0 ) {
                ll c = (ll)(N*a*b)/((ll)(4*a*b)-(ll)(N*(a+b)));
                if(c>0){
                    cout<<a<<" "<<b<<" "<<c<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
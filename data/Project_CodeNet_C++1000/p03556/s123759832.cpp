#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll a[100000];
int main(void){
    ll n;
    cin>>n;
    ll i=0;
    while(true){
        a[i]=i*i;
        if(i*i>=1000000000){
            break;
        }
        i++;
    }
    for(int j=0;j<=i;j++){
        if(a[j]<=n){
            
        }else{
            cout<<a[j-1]<<endl;
            return 0;
        }
    }
    
}

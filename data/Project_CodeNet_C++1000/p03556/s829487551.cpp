#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;

    ll k=1;
    n+=1;
    while(n--&&k==1){
        for(ll i=1; i*i<=n; i++){
            if(i*i==n){
                cout<<n<<endl;
                k=0;
                break;
            }
        }

    }

}

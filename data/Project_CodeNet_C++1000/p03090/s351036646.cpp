#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;

vector<ll> to[100010];


int main(){
    ll n;cin>>n;
    if(n%2==0){
        cout<<n*(n-1)/2-n/2<<endl;
        rep(i,1,n+1){
            rep(j,i+1,n+1){
                if(i+j!=n+1)cout<<i<<" "<<j<<endl;
            }
        }
    }
    if(n%2==1){
        cout<<n*(n-1)/2-n/2<<endl;
        rep(i,1,n+1){
            rep(j,i+1,n+1){
                if(i+j!=n)cout<<i<<" "<<j<<endl;
            }
        }
    }
}






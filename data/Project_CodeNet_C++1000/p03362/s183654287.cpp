#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;

void Sieve(vector<bool> &IsPrime,ll n){
    rep(i,n+1) IsPrime[i]=1;
    IsPrime[0]=IsPrime[1]=0;
    for(ll i=2;i*i<=n;i++){
        if(IsPrime[i]){
            for(ll j=i;i*j<=n;j++){
                IsPrime[i*j]=0;
            }
        }
    }
}

int main(){
    ll n;
    cin>>n;
    vector<bool> isp(55556);
    Sieve(isp,55555);
    ll now=0;
    rep(i,n){
        while(1){
            now++;
            if(isp[now]&&now%10==1){
                cout<<now<<' ';
                break;
            }
        }
    }
    return 0;
}
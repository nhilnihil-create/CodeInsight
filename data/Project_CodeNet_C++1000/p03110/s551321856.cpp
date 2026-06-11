#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using P = pair<int,int>;
using ll = long long; 

int main(){
    ll n;
    long double ans=0;
    long double bitcoin=0;
    long double money;
    string unit;
    cin>>n;
    rep(i,n){
        cin>>money>>unit;
        if(unit=="JPY"){
            ans+=money;
        }else{
            bitcoin+=money;
        }
    }

    ans+=bitcoin*380000.0;

    // cout<<bitcoin<<endl;
    cout<<ans<<endl;
}


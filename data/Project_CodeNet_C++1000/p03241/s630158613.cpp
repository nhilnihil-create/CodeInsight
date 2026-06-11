#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using P=pair<int,int>;
int main() {
    ll n,m;cin>>n>>m;
    ll maximum;
    if(n==1){
        maximum=m;
    }
    else{
        for(ll i=1;i<=m/n;i++){
            if(m%i==0) maximum=i;
        }
    }

    cout<<maximum<<endl;
}
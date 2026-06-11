#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<random>
#include<stdio.h>
using namespace std;

typedef long long ll;

int main(){
    ll N;
    string S;
    ll Q;
    vector<ll> K(Q);
    cin>>N;
    cin>>S;
    cin>>Q;
    for (ll i=0;i<Q;i++){
        cin>>K[i];
    }
    for (ll j=0;j<Q;j++){
        ll k=K[j];
        ll d=0;
        ll m=0;
        ll dm=0;
        ll ans=0;
        for (ll i=0;i<N-1;i++){
            d+=(S[i]=='D');
            m+=(S[i]=='M');
            dm+=d*(S[i]=='M');
            if (i>k-2){
                d-=(S[i+1-k]=='D');
                dm-=m*(S[i+1-k]=='D');
                m-=(S[i+1-k]=='M');
            }
            ans+=dm*(S[i+1]=='C');
        }
        cout<<ans<<endl;
    }
}


#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n;
    cin >> n;
    vector <ll> s(n+1,n+1);
    ll c;
    rep(i,n){
        cin >> c;
        s[c]=i;
    }

    int k=1,kmax=0;
    rep(i,n){
        if(s[i]<s[i+1]){
            ++k;
        }
        else{
            kmax=max(k,kmax);
            k=1;
        }
    }

    kmax=max(k,kmax);

    cout << n-kmax << endl;
    

    return 0;
}
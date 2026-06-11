#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n,m;
    cin >> n >> m;

    vector <vector <ll>> ab(n,vector <ll> (2));

    rep(i,n){
        cin >> ab[i][0] >> ab[i][1];
    }

    sort(ab.begin(),ab.end());
    ll k=0,ans=0,j=0;

    while(k<m){
        k+=ab[j][1];
        if(k>m){
            ans+=ab[j][0]*(ab[j][1]-(k-m));
        }
        else{
            ans+=ab[j][0]*ab[j][1];
        }
        ++j;
    }

    cout << ans << endl;

    

    return 0;
}
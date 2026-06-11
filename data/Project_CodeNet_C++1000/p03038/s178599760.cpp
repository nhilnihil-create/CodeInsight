#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n,m;
    cin >> n >> m;
    vector <ll> a(n);
    vector <vector <ll>> bc(m,vector <ll> (2));

    rep(i,n){
        cin >> a[i];
    }

    rep(i,m){
        cin >> bc[i][1] >> bc[i][0];
    }

    sort(bc.begin(),bc.end());
    sort(a.begin(),a.end());
    int k=0;

    rep(i,m){
        
        if(a[k]>=bc[m-i-1][0]){
            break;
        }
        rep(j,bc[m-i-1][1]){
            if(a[k]>=bc[m-i-1][0]){
                break;
            }
            a[k]=bc[m-i-1][0];
            ++k;
            if(k==n){
                break;
            }
        }
    }

    ll ans=0;
    rep(i,n){
        ans+=a[i];
        //cout << a[i] << endl;


    }

    cout << ans << endl;
    

    return 0;
}
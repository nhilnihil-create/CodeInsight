#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n;
    cin >> n;
    vector <ll> a(n);

    ll kk;
    rep(i,n){
        cin >> kk;
        if(i==0){
            a[i]=kk;
        }
        else{
            a[i]=kk+a[i-1];
        }
    }

    sort(a.begin(),a.end());
    ll ans=0;
    ll k=0;
    rep(i,n){
        if(a[i]==0){
            ++ans;
        }

        if(i==0){
            k=1;
        }
        else if(a[i]==a[i-1]){
            ++k;
        }
        else{
            if(k>=2){
                ans+=k*(k-1)/2;
            }
            k=1;
        }
    }

    if(k>=2){
        ans+=k*(k-1)/2;
    }

    /*rep(i,n){
        cout << a[i] << endl;
    }*/

    cout << ans << endl;
    

    return 0;
}
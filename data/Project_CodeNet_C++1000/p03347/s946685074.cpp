#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector <ll> a(n+1);
    rep(i,n){
        cin >> a[n-i-1];
    }
    a[n]=0;

    ll ans=0;
    int k=0;
    rep(i,n){
        if(a[i]-a[i+1]==1){
            if(k==0){
                ans+=a[i];
                k=1;
            }
        }
        else if(a[i]==a[i+1]){
            if(k!=1){
            ans+=a[i];
            }
            k=0;
        }
        else if(a[i]<a[i+1]){
            if(k!=1){
            ans+=a[i];
            }
            k=0;
        }
        else{
            cout << -1 << endl;
            return 0;
        }

        //cout << i << " " << a[i] << " "<< ans << endl;
    }

    if(a[n-1]!=0){
        ans=-1;
    }

    cout << ans << endl;


    

    return 0;
}
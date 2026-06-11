#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n,h;
    cin >> n >> h;
    ll bs=0;
    ll am=0;
    ll a,bb;
    vector <ll> b(n);
    rep(i,n){
        cin >> a >> b[i];
        am=max(am,a);
    }

    sort(b.begin(),b.end());
    ll ans,k;

    rep(i,n){
        if(am>=b[n-i-1]){
            ans=h/am;
            if(h%am!=0){
                ++ans;
            }
            ans+=i;
            h=-1;
            break;

        }
        else{
            h-=b[n-i-1];
            if(h<=0){
                ans=i+1;
                break;
            }
        }
    }

    if(h>0){
        ans=h/am;
            if(h%am!=0){
                ++ans;
            }
            ans+=n;
    }

    cout << ans << endl;
    return 0;
}
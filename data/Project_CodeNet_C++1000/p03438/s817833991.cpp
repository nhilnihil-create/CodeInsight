#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector <ll> a(n),b(n);
    ll aa=0,bb=0;
    rep(i,n){
        cin >> b[i];
    }
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n){
        //cin >> a[i] >> b[i];
        if(b[i]>=a[i]){
            bb+=b[i]-a[i];
        }
        else if(a[i]>b[i]){
            if((a[i]-b[i])%2==0){
                aa+=(a[i]-b[i])/2;
            }
            else{
                aa+=(a[i]-b[i])/2+1;
                ++bb;
            }
        }
    }

    if(aa>=bb){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    
    

    return 0;
}
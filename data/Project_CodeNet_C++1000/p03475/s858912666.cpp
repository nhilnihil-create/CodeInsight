#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector <int> c(n),s(n),f(n),t(n,0);
    rep(i,n-1){
        cin >> c[i] >> s[i] >> f[i];
    }

    int tt,a;

    rep(i,n-1){
        //cout << i << endl;
        tt=s[i];
        rep(j,n-i-1){
            //cout << j << endl;
            tt+=c[i+j];
            if(j==n-i-2){
                break;
            }
            if(tt<s[i+j+1]){
                tt=s[i+j+1];
            }
            if(tt%f[i+j+1]!=0){
                a=tt%f[i+j+1];
                tt+=f[i+j+1]-a;
            }
        }
        t[i]=tt;
    }

    rep(i,n){
        cout << t[i] << endl;
    }

    
    

    return 0;
}
#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector <int> b(n);
    vector <int> ans;
    rep(i,n){
        cin >> b[i];
    }

    int k,k2=0;
    rep(i,n){
        k=n-i;
        rep(j,n){
            //cout << k << endl;
            if(b[n-j-1]==k){
                //cout << k << n-j-1 << endl;
                b[n-j-1]=-10;
                ans.push_back(k);
                break;
            }
            if(b[n-j-1]!=-10){
                --k;
            }
            if(j==n-1){
                //cout << i << endl;
                k2=1;
            }
        }
    }

if(k2==0){
    rep(i,n){
        cout << ans[n-i-1] << endl;
    }
}
else{
    cout << -1 << endl;
}

    

    return 0;
}
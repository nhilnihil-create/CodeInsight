#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;

    vector <ll> w(n+1),b(n+1);
    ll ww=0,bb=0;
    string s2;
    w[0]=0;
    b[n]=0;
    rep(i,n){
        s2=s[i];
        if(s2=="."){
            ++ww;
        }
        w[i+1]=ww;
        s2=s[n-i-1];
        if(s2=="#"){
            ++bb;
        }
        b[n-i-1]=bb;
    }

    ll ans=n;
    rep(i,n+1){
        ans=min(ans,n-w[i]-b[i]);
    }

    cout << ans << endl;
    

    return 0;
}
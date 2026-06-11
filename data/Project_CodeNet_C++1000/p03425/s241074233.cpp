#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;


int main() {
    int n; cin >> n;
    vector<ll> c(5);//counter。m,a,r,c,hの順。
    rep(i,n){
        string t;
        cin >> t;
        if(t.at(0)=='M') c[0]++;
        else if(t.at(0)=='A') c[1]++;
        else if(t.at(0)=='R') c[2]++;
        else if(t.at(0)=='C') c[3]++;
        else if(t.at(0)=='H') c[4]++;   
    }
    ll ans=0;
    rep(i,3){
        for(int j=i+1;j<4;j++){
            for(int k=j+1;k<5;k++){
                ans+=c[i]*c[j]*c[k];
            }
        }
    }
    cout << ans << endl;
}
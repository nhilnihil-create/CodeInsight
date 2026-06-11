#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<ll> a(5,0);
    rep(i,n){
        if(s[i][0]=='M') ++a[0];
        else if(s[i][0]=='A') ++a[1];
        else if(s[i][0]=='R') ++a[2];
        else if(s[i][0]=='C') ++a[3];
        else if(s[i][0]=='H') ++a[4];
    }
    ll ans=0;
    for(int i=0;i<3;++i){
        if(a[i]==0) continue;
        for(int j=i+1;j<4;++j){
            if(a[j]==0) continue;
            for(int k=j+1;k<5;++k){
                if(a[k]==0) continue;
                ans+=(a[i]*a[j]*a[k]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}   
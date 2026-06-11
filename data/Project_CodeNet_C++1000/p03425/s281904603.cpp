#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int a[5];

int main(){
    int n;
    cin>>n;
    vector<string>s(n);
    rep(i,n)cin>>s[i];
    string t="MARCH";
    rep(i,n){
        rep(j,5){
            if(t[j]==s[i][0])a[j]++;
        }
    }
    ll ans=0;
    for(int i=0; i<3; ++i){
        for(int j=i+1; j<4; ++j){
            for(int k=j+1; k<5; ++k){
                ans+=(ll)a[i]*a[j]*a[k];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
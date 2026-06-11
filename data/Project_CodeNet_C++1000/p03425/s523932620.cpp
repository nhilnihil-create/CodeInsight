#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {

    ll n;cin>>n;
    string s;
    vector<pair<char,ll>> v(5);
    vector<char> c={'M','A','R','C','H'};
    rep(i,5){
        v[i].first=c[i];
    }
    rep(i,n){
        cin>>s;
        char ini=s[0];
        rep(j,5){
            if(v[j].first==ini){
                v[j].second++;
                break;
            }
        }
    }
    ll sum=0;
    rep(i,3){
        ll a=v[i].second;
        for(int j=i+1;j<4;j++){
            ll b=v[j].second;
            for(int k=j+1;k<5;k++){
                ll c=v[k].second;
                sum+=a*b*c;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}

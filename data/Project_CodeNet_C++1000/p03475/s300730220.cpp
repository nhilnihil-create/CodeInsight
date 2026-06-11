#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    ll n;cin >>n;
    vector<ll>c(n-1);
    vector<ll>s(n-1);
    vector<ll>f(n-1);
    for (int i = 0; i < n - 1; ++i) {
        cin >>c[i]>>s[i]>>f[i];
    }
    ll now=0;
    for (int i = 0; i <n-1; ++i) {
        ll j=i;
        now=0;
        while(1){
            if(j==n-1)break;
            if(now<s[j]){
                now=s[j];
            }
            ll time=(now%f[j])?f[j]-now%f[j]:0;
            now+=time;
            now+=c[j];
//            cout <<j <<" "<<now<<endl;
            j++;
        }
        cout <<now<<endl;
    }
    cout <<0<<endl;
    return 0;
}
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
    ll k;cin >>k;
    vector<ll>a(k);
    for (int i = 0; i < k; ++i) {
        cin >>a[i];
    }
    reverse(all(a));
    a.push_back(1);
    ll mint=2,mx=2;
    if(a[0]!=2){
        cout <<-1<<endl;
        return 0;
    }
    for (int i = 0; i < k; ++i) {
        mx+=a[i]-1;
        mx -= mx % a[i + 1];
        ll cost = (mint % a[i + 1]) ? a[i + 1] - mint % a[i + 1] : 0;
        mint += cost;
        if(mint>mx){
            cout <<-1<<endl;
            return 0;
        }
    }
    cout <<mint<<" "<<mx<<endl;
    return 0;
}
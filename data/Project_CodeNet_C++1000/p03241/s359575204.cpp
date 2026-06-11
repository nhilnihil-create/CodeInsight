#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<long long> enum_divisors(long long N){
    vector<long long> res;
    for(long long i=1;i*i<=N;i++){
        if(N%i==0){
            res.push_back(i);
            if(N/i!=i) res.push_back(N/i);
        }
    }
    sort(res.begin(),res.end());
    return res;
}

int main(){
    ll n,m;
    cin >> n >> m;
    auto em=enum_divisors(m);
    ll ans=1;
    for(ll i=0;i<em.size();i++){
        if(em[i]>=n){
            ans=m/em[i];
            break;
        }
    }
    cout << ans << endl;
}

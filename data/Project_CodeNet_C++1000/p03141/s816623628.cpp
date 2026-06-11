#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ll N;
    cin >> N;
    vector<pair<ll,pair<ll,ll>>> v(N);
    for(int i = 0; i < N; i++){
        ll tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        v[i] = make_pair(tmp1 + tmp2,make_pair(tmp1,tmp2));
    }
    sort(v.begin(),v.end(), greater<pair<ll,pair<ll,ll>>>());

    ll ans = 0;

    for(int i = 0; i < N; i++){
        if(i % 2 == 0){
            ans += v[i].second.first;
        }else{
            ans -= v[i].second.second;
        }
    }

    cout << ans << endl;
}


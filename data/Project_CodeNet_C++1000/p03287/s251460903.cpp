#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll N, M;
ll A[100010];
ll sum;
map<int, ll> mp;
int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    for(int i = 1; i <= N; i++){
        sum += A[i];
        sum %= M;
        mp[sum]++;
    }
    ll ans = 0;
    for(auto& u : mp){
        if(u.first == 0) ans += u.second;
        ans += u.second * (u.second - (ll)1) / (ll)2;
    }
    cout << ans << endl;
    return 0;
}
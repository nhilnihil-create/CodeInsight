#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main(){
    ll N, A, B;
    cin >> N >> A >> B;
    if(!(N <= A * B && A + B - 1 <= N)){
        cout << -1 << endl;
        return 0;
    }
    vector<ll> v[B];
    ll low = 1, up = N;
    for(ll i = B - 1; 0 <= i; i--){
        v[i].push_back(B - i);
        low = B - i;
    }
    for(ll i = N; v[0].size() < A; i--){
        v[0].push_back(i);
        up = i;
    }
    sort(v[0].begin(), v[0].end());
    ll index = B - 1;
    for(ll i = low + 1; i < up; i++){
        v[index].push_back(i);
        index--;
        if(!index) index = B - 1;
    }
    for(ll i = 0; i < B; i++) for(ll u : v[i]) cout << u << " ";
    cout << endl;
    return 0;
}
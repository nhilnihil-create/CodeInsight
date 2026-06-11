#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <algorithm>
using ll = long long;

// tgtよりも低い要素の個数
ll bs_lowers(ll tgt, const vector<ll> &list){

    ll left = 0, right = list.size(), mid;
    while (left<right){
        mid = (left+right)/2;
        if (list[mid]<tgt) left = mid+1;
        if (list[mid]>=tgt) right = mid;
    }
    return (left+right)/2;
}

// tgtよりも高い要素の個数
ll bs_uppers(ll tgt, const vector<ll> &list){

    ll left = 0, right = list.size(), mid;
    while (left<right){
        mid = (left+right)/2;
        if (list[mid]>tgt) left = mid+1;
        if (list[mid]<=tgt) right = mid;
    }
    return (left+right)/2;
}


int main(){

    // O(N)
    ll N; cin>>N;
    vector<ll> A(N), B(N), C(N);
    for (ll n=0; n<N; n++) cin>>A[n];
    for (ll n=0; n<N; n++) cin>>B[n];
    for (ll n=0; n<N; n++) cin>>C[n];

    // O(NlogN)
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    reverse(C.begin(), C.end());

    // O(N) * O(logN)
    ll ans = 0;
    for (ll n=0; n<N; n++){

        ll A_lowers = bs_lowers(B[n], A);
        ll C_uppers = bs_uppers(B[n], C);

        ans += A_lowers*C_uppers;

    }
    cout << ans << endl;

}
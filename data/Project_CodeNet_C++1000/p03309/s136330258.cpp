#define _LIBCPP_DEBUG 0
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD = 1e9 + 7;

int main(void){

    ll N; cin>>N;
    vector<ll> A(N);
    vector<ll> sortedA(N);
    for (int i = 0; i < N; ++i) {
        cin>>A[i];
        int tmp=A[i];
        sortedA[i]=tmp-(i+1);
    }
    sort(sortedA.begin(), sortedA.end());
    ll mid = sortedA[N/2];
    ll ans=0;
    for (int i = 0; i < N; ++i) {
        ans += abs(A[i]-(mid+i+1));
    }
    cout<<ans<<endl;


}
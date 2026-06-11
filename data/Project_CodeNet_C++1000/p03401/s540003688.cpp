#define _LIBCPP_DEBUG 0
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD = 1e9 + 7;

int main(void){

    int N; cin>>N;
    vector<int> A(N+2,0);
    ll sum = 0;
    for (int i = 1; i <= N; ++i) {
        cin>>A[i];
        sum += abs(A[i]-A[i-1]);
    }
    sum+=abs(A[N+1]-A[N]);

    for (int i = 1; i <= N; ++i) {
        ll ans = 0;
        ans=abs(A[i+1]-A[i-1])-(abs(A[i-1]-A[i])+abs(A[i]-A[i+1]));
        cout<<sum+ans<<endl;
    }
}
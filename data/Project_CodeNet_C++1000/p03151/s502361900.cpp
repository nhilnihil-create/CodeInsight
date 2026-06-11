#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<ll> A(N),B(N);
    for (int i=0;i<N;++i) cin >> A[i];
    for (int i=0;i<N;++i) cin >> B[i];
    ll sum=0;
    for (int i=0;i<N;++i){
        A[i]-=B[i]; sum+=A[i];
    }
    if (sum<0){cout << -1 << '\n'; return 0;}
    sort(A.begin(),A.end());
    int ans=0,last=N;
    for (int i=0;i<N;++i) if (A[i]<0){
        ++ans;
        if (last==N) --last;
        while(A[i]<0){
            ll use=min(-A[i],A[last]);
            A[i]+=use; A[last]-=use;
            if (A[i]<0) --last;
        }
    }
    cout << ans+(N-last) << '\n';
}
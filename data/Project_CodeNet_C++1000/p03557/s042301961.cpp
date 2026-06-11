#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N;
    cin>>N;
    long long int A[N],B[N],C[N];
    rep(i,N)cin>>A[i];
    rep(i,N)cin>>B[i];
    rep(i,N)cin>>C[i];
    sort(A,A+N);
    sort(B,B+N);
    sort(C,C+N);
    long long int ans=0;
    rep(i,N){
        long long int a = lower_bound(A,A+N,B[i]) - A;
        long long int c = upper_bound(C,C+N,B[i]) - C;
        ans += a*(N-c);
    }
    cout<<ans<<endl;
    return 0;
}
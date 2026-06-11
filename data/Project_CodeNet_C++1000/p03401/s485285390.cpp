#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int N;
    cin>>N;

    vector<int> A(N+2, 0);
    vector<int> B(N+1, 0);
    ll sum = 0;    
    for(int i=1; i<=N; i++){
        cin>>A[i];
        B[i-1] = abs(A[i]-A[i-1]);
        sum += abs(A[i]-A[i-1]);
    }

    B[N] = abs(A[N+1]-A[N]);
    sum += abs(A[N+1]-A[N]);

    for(int i=1; i<=N; i++){
        cout<< sum - B[i-1] - B[i] +abs(A[i-1]-A[i+1]) <<endl;
    }

    return 0;
}
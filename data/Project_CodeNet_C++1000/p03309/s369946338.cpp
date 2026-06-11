#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin>>A[i];

    for(int i=0; i<N; i++) A[i] -= (i+1);

    sort(A.begin(),A.end());

    int med = A[N/2];

    long long ans = 0;

    for(int i=0; i<N; i++){
        ans += abs(A[i]-med);
    }

    cout<<ans<<endl;

    return 0;
}
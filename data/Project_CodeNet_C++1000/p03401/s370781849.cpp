#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> A(N+2);
    vector<long long> sum(N+2,0);
    for(int i=1; i<=N; i++) cin>>A[i];

    A[0] = A[N+1] = 0; 

    for(int i=1; i<=N+1; i++){
        sum[i] =  sum[i-1]+abs(A[i]-A[i-1]);
    }

    /*
    iは通らない場所

    始まりから、iー１番目の金額
    sum[i-1]

    i-1からi+1
    abs(A[i-1]-A[i+1])

    i+1からN+1
    sum[N+1] - sum[i+1]
    */

    for(int i=1; i<=N; i++){
        long long ans;
        ans = sum[i-1] + sum[N+1] + abs(A[i-1]-A[i+1]) -sum[i+1];
        cout<<ans<<endl;
    }

    return 0;
}
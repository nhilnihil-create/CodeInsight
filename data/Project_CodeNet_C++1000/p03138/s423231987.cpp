#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ull N, K;
    cin >> N >> K;
    vector<ull> A(N);
    vector<int> bCount(64, 0);
    for(int i=0;i<N;i++){
        cin >> A[i];
        for(int j=0; j<64; j++){
            if(A[i] & ((ull)1<<j)) bCount[j]++;
        }
    }
    ull X = 0;
    for(int j=63; j>=0; j--){
        if(2 * bCount[j] < N){
            auto x = X | (ull)1 << j;
            if(x > K) continue;
            X = x;
        }
    }
    ull res = 0;
    for(auto v : A) res += X ^ v;
    cout<<res<<endl;

    return 0;
}
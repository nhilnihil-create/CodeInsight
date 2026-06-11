#include<bits/stdc++.h>
using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;
    vector <long long> V(N+1, 0);
    for (long long i=0; i<N; i++) {
        long long A;
        cin >> A;
        V.at(A)++;
    }
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
    long long ans=0; 
    for (long long i=0; i<K; i++) {
        ans += V.at(i);
    }
    cout << N-ans;
}
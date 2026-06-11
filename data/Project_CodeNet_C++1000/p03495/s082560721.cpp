#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int A[N];
    for (int i=0; i<N; i++) cin >> A[i];
    int B[210000]={0};
    for (int i=0; i<N; i++) B[A[i]]++;
    sort (B, B+210000, greater <int>());
    int total=0;
    for (int i=K; i<N; i++) total+=B[i];
    cout << total<< endl;
}

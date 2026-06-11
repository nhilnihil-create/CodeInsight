#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    int N;
    cin >> N;
    vector<int> A(N+2);
    A[0] = 0;
    A[N+1] = 0;
    for(int i=1; i<=N; i++) cin >> A[i];
    int total_cost = 0;

    for(int i=0; i<=N; i++) {
        total_cost += abs(A[i]-A[i+1]);
    }
    
    for(int i=1; i<=N; i++) {
        int c = total_cost - abs(A[i]-A[i-1]) - abs(A[i]-A[i+1]) + abs(A[i-1] - A[i+1]);
        cout << c << endl;
    }
}
#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long N, M, X;
    cin >> N >> M >> X;
    vector<long long> A(M);
    X--;
    for(int i = 0; i < M; i++) {
        cin >> A[i];
        A[i]--;
    }
    vector<long long> cost(N + 1, 0);
    for(int i = 0; i < M; i++) cost[A[i]]++;
    long long ans = 0;
    for(int i = 0; i < X; i++) ans += cost[i];
    cout << min(ans, M - ans) << endl;
}
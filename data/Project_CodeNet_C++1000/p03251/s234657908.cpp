#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,M,X,Y;
    cin >> N >> M >> X >> Y;
    vector<int> A(N), B(M);
    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < M; ++i) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    if(A[N-1] > X && A[N-1] < B[0] && B[0] <= Y) cout << "No War" << '\n';
    else cout << "War" << '\n';
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long gcd(long long x, long long y){
    if(x < y) swap(x, y);
    if(x % y == 0) return y;
    return gcd(y, x % y);
}
int main(){
    int N;
    cin >> N;
    vector<long long> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    vector<long long> R(N), L(N);
    L[0] = A[0];
    R[0] = A[N - 1];
    for(int i = 1; i < N; i++){
        L[i] = gcd(L[i - 1], A[i]);
        R[i] = gcd(R[i - 1], A[N - 1 - i]);
    }
    long long g = 0;
    for(int i = 0; i < N; i++){
        if(i == 0) g = max(g, R[N - 2]);
        else if(i == N - 1) g = max(g, L[N - 2]);
        else g = max(g, gcd(L[i - 1],R[N - i - 2]));
    }
    cout << g << endl;
}

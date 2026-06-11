#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
vector <int> x(10000);
int main() {
    vector <int> A(3);
    cin >> A[0] >> A[1] >> A[2];
    int K;
    cin >> K;
    for(int i = 0; i < K; i++){
        sort(A.begin() , A.end());
        A[2] *= 2;
    }
    cout << A[0] + A[1] + A[2] << endl;
}
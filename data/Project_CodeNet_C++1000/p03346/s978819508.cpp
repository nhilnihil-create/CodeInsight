#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    vector<int> A(N,0);
    vector<int> pq(N+1);
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        pq.at(A.at(i)) = 1 + pq.at(A.at(i) - 1);
        ans = max(pq.at(A.at(i)),ans);
    }
    cout << N - ans << endl;
    

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long N, A, B;
    cin >> N >> A >> B;

    if (N < A+B-1 || A*B < N) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> v;
    
    for (int i=N-A+1; i<=N; ++i) {
        v.push_back(i);
    }
    N -= A;

    int m;
    for (int i=B-1; i>0; --i) {
        m = min(A, N-i+1);
        for (int j=N-m+1; j<=N; ++j) {
            v.push_back(j);
        }
        N -= m;
    }

    for (int i=0; i<(int)v.size(); ++i) {
        cout << (i == 0 ? "" : " ") << v[i];
    }
    cout << endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
    int N; cin >> N;
    int L[10]; rep(i, N) cin >> L[i];
    sort(L, L + N);
    int S = 0; rep(i, N - 1) S += L[i];
    if (S > L[N - 1]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
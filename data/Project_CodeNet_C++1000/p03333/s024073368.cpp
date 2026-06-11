#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> L(N+1), R(N+1);
    for(int i=0; i<N; i++) cin >> L[i] >> R[i];
    sort(L.rbegin(), L.rend());
    sort(R.begin(), R.end());
    int64_t ans = 0;
    for(int i=0; i<=N; i++) if(L[i] > R[i]) ans += 2*(L[i]-R[i]);
    cout << ans << endl;
}
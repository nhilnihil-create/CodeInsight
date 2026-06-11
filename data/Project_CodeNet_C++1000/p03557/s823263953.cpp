#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int N;
    cin >> N;
    vector<int>A(N);
    vector<int>B(N);
    vector<int>C(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> B[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> C[i];
    }
    int ans = 0;
    sort(A.begin(),A.end());
    sort(C.begin(),C.end());
    for(int i = 0; i < N; i++) {
        int cnt = 0;
        cnt += lower_bound(A.begin(),A.end(),B[i])-A.begin();
        cnt *= C.end()-(upper_bound(C.begin(),C.end(),B[i]));
        ans += cnt;
    }
    cout << ans << endl;
}

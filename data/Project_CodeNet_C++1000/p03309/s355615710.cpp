#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int N;
    cin >> N;
    vector<int>A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]-=i-1;
    }
    int ans = 0;
    sort(A.begin(),A.end());
    for(int i = 0; i < N; i++) {
        ans+=abs(A[i]-(A[N/2]));
    }
    cout << ans << endl;
}
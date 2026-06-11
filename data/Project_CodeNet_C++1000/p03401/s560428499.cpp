#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n); ++i)
typedef long long ll;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> A(N+2);
    A[0] = 0; A[N+1] = 0;
    for(int i=1;i<=N;i++) cin >> A[i];
    ll sum = 0;
    for(int i=1;i<=N+1;++i) sum += abs(A[i] - A[i-1]);
    for(int i=1;i<N+1;++i) {
        ll res = sum + abs(A[i+1]-A[i-1]) - abs(A[i]-A[i-1]) - abs(A[i+1]-A[i]);
        cout << res << endl;
    }
    
}

#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }

int main() {
    vector<int> num = {6,2,5,5,4,5,6,3,7,6};
    int N,M;
    cin >> N >> M;
    vector<int> A(M);
    for(int i=0;i<M;++i) {
        cin >> A[i];
    }
    sort(A.rbegin(),A.rend());

    vector<int> dp(N+1,-999);

    dp[0]=0;
    for(int i=1;i<=N;++i) {
        int max = 0;
        for(int j=0;j<M;++j) {
            if (i-num[A[j]]>=0&&i-num[A[j]]<=N)
                if (dp[i-num[A[j]]]>=0)
                    if (max < dp[i-num[A[j]]]+1)
                        max = dp[i-num[A[j]]]+1;
        }
        if (max > 0) dp[i] = max;
    }

    //cout << dp[N] << endl;
    int tmp=N;
    for (int i=0;i<dp[N];++i) {
        for (int j=0;j<M;++j) {
            if (tmp-num[A[j]]>=0 && dp[tmp-num[A[j]]]==dp[tmp]-1) {
                cout << A[j];
                tmp-=num[A[j]];
                break;
            }
        }
    }

    return 0;
}

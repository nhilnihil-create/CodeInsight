#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int weight[10]={0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int INF = 1e5;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    int min_A=-INF;
    for(int m=0; m<M; m++) {
        cin >> A[m];
        min_A = min(min_A, A[m]);
    }
    
    sort(A.begin(), A.end(), greater<int>());
    
    vector<int> dp(N+1, -INF);
    dp[0] = 0;
    
    for(int n=1; n<=N; n++) {
        for(int m=0; m<M; m++) {
            int A_w=weight[A[m]];
            if(n-A_w>=0 && dp[n-A_w]!=-INF) {
                dp[n] = max(dp[n-A_w]+1, dp[n]);
            }
        }
    }
    
    int count=N;
    while(count>0) {
        for(int m=0; m<M; m++) {
            int A_w=weight[A[m]];
            if(count-A_w>=0 && dp[count-A_w]+1==dp[count]) {
                cout << A[m];
                count -= A_w;
                break;
            }
        }
    }
    cout << endl;
    
    return 0;
    
}
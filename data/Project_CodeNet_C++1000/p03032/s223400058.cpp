#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<long long> V(N);
    for(int i = 0; i < N; i++) cin >> V[i];
    long long ans = 0;
    if(N <= K){
        for(int i = 0; i < N; i++){
            if(V[i] >= 0) ans += V[i];
        }
        cout << ans << endl;
        return 0;
    }
    for(int x = 0; x <= K; x++){
    for(int i = 0; i <= x; i++){
        int s = i, t = x - i;
        for(int j = 0; j <= s; j++){
            priority_queue<int, vector<int>, greater<int>> q;
            long long res = 0;
            for(int k = 0; k < s - j; k++){
                q.push(V[k]);
            }
            for(int k = 0; k < j && !q.empty(); k++) q.pop();
            int si = q.size();
            for(int l = 0; l < si; l++){
                res += q.top();
                q.pop();
            }
            for(int k = 0; k <= t; k++){
                priority_queue<int, vector<int>, greater<int>> q1;
                long long res2 = res;
                for(int l = 0; l < t - k; l++){
                    q1.push(V[N - 1 - l]);
                }
                for(int l = 0; l < k && !q1.empty(); l++) q1.pop();
                int sie = q1.size();
                for(int l = 0; l < sie; l++){
                    res2 += q1.top();
                    q1.pop();
                }
                ans = max(ans, res2);
            }
        }
    }
    }
    cout << ans << endl;
}
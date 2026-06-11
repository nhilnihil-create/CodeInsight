#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    long long ans = 0;
    vector<long long> V(N);
    for(int i = 0; i < N; i++) cin >> V[i];
    int kosu = min(N, K);
    for(int i = (kosu + 1) / 2; i <= kosu; i++){
        for(int j = i - 1; j >= -1; j--){
            priority_queue<long long, vector<long long>, greater<long long>> q;
            for(int k = 0; k < i; k++){
                q.push(V[(j - k + N) % N]);
            }
            for(int k = 0; k < K - i; k++){
                if(q.top() > 0 || q.empty()) break;
                q.pop();
            }
            long long res = 0;
            while(!q.empty()){
                res += q.top();
                q.pop();
            }
            ans = max(ans, res);
        }
    }
    cout << ans << endl;
}
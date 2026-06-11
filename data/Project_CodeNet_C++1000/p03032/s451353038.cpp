#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    int K; cin >> K;
    int R = min(N, K);
    vector<int> V(N);
    rep(i, N){
        cin >> V[i];
    }

    int fa = 0;
    for (int i = 0; i <= R; i++){
        for (int j = 0; j <= R-i; j++){
            priority_queue<int, vector<int>, greater<int> > Q;
            for (int k = 0; k < i; k++){
                Q.push(V[k]);
            }
            for (int k = 0; k < j; k++){
                Q.push(V[N-1-k]);
            }
            for (int k = 0; k < K-i-j; k++){
                if(Q.empty())break;
                int x = Q.top();
                if(x < 0){
                    Q.pop();
                } else {
                    break;
                }
            }
            int ans = 0;
            while(!Q.empty()){
                int y = Q.top(); Q.pop();
                ans += y;
            }
            fa = max(fa, ans);
        }
    }

    cout << fa << endl;

    return 0;
}
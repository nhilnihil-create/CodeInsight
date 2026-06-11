#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define INF INT_MAX/2

using namespace std;

int N, K;

int main() {
    cin >> N >> K;
 
    queue<int> que1;
    que1.push(1);
 
    rep(i, N) {
        queue<int> que0;
 
        while (!que1.empty()) {
            que0.push(que1.front() * 2);
            que0.push(que1.front() + K);
			que1.pop();
        }
        swap(que1, que0); 
    }
 
    int ans = INF;
    while (!que1.empty()) {
        ans = min(ans, que1.front());
		que1.pop();
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
int nature(int a) {
  return max(a, -a);
}
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> X(N);
    for (int i = 0; i < N; i++) {
        cin >> X.at(i);
    }
    int answer = 1000000000;
    for (int i = 0; i <= N - K; i++) {
        answer = min(answer, X.at(i + K - 1) - X.at(i) + min(nature(X.at(i)), nature(X.at(i + K - 1))));
    }
    cout << answer << endl;
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;

    vector<int> Ps(N);
    for (int i = 0; i < N; i++) cin >> Ps[i];

    vector<int> ans(N + 1, 0);
    for (int i = 0; i < N; i++) {
        ans[Ps[i]] = ans[Ps[i] - 1] + 1;
    }
    int a = 0;
    for (int i = 0; i < N + 1; i++) {
        a = max(a, ans[i]);
    }
    cout << N - a << endl;

    
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string S;
    int K;
    cin >> S >> K;
    int N = S.size();

    //全探索。S[i]に対して部分文字列の配列を作っていく
    vector<string> vec;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= K; j++) {
            vec.push_back(S.substr(i, j));
        }
    }

    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    string ans;
    ans = vec[K-1];
    cout << ans << endl;
    return 0;
}

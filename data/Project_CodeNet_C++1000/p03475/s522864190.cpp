#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N; cin >> N;
    vector<long long>C(N - 1), S(N - 1), F(N - 1);
    for (long long i = 0; i < N - 1; i++) {
        cin >> C.at(i) >> S.at(i) >> F.at(i);
    }
    vector<long long>ans(N, 0);
    for (long long i = 0; i < N; i++) {
        if (i == N - 1) continue;
        else {
            ans.at(i) += S.at(i);
            for (long long j = i; j < N - 1; j++) {
                if (ans.at(i) < S.at(j)) {
                    ans.at(i) = S.at(j) + C.at(j);
                }
                else if ((ans.at(i) - S.at(j)) % F.at(j) == 0) ans.at(i) += C.at(j);
                else {
                    long long sum = (ans.at(i) - S.at(j)) / F.at(j) + 1;
                    ans.at(i) = S.at(j) + sum * F.at(j) + C.at(j);
                }
            }
        }
    }
    for (long long i = 0; i < N; i++) {
        cout << ans.at(i) << endl;
    }
}
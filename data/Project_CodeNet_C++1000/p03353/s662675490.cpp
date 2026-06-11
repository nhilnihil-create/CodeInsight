#include "bits/stdc++.h"

using namespace std;

void Main() {
    string s;
    cin >> s;
    int K;
    cin >> K;

    int N = s.size();
    set<string> topK;
    for (int i = 0; i < N; ++i) {
        int M = min(5, N - i);
        for (int j = 1; j <= M; ++j) {
            string subs = s.substr(i, j);
            if (topK.size() < K) {
                topK.insert(subs);
            }
            else {
                for (auto e : topK) {
                    if (subs < e) {
                        topK.insert(subs);
                        if (topK.size() > K) {
                            topK.erase(*(topK.rbegin()));
                        }
                    }
                }
            }
        }
    }
    cout << *(topK.rbegin()) << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}

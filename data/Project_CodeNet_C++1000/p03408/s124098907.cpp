#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main() {

    uint N;
    cin >> N;
    unordered_map<string, int> S;
    for(uint i=0; i<N; ++i) {
        string key;
        cin >> key;
        if (S.find(key) == S.end())
            S[key] = 1;
        else
            ++S[key];
    }

    uint M;
    cin >> M;
    unordered_map<string, int> T;
    for(uint i=0; i<M; ++i) {
        string key;
        cin >> key;
        if (T.find(key) == T.end())
            T[key] = 1;
        else
            ++T[key];
    }

    int scoreMax = 0;
    for (auto& p: S) {
        int score = p.second;
        string key = p.first;
        if (T.find(key) != T.end())
            score -= T[key];
        if (score > scoreMax) {
            scoreMax = score;
        }
    }

    if (scoreMax > 0)
        cout << scoreMax << endl;
    else
        cout << 0 << endl;
}

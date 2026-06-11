#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    int K;
    cin >> S >> K;
    vector<string>vec;
    for(int i = 0; i < S.size(); i++) {
        for(int j = 0; j <= K; j++) {
            vec.push_back(S.substr(i,j+1));
        }
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    cout << vec[K-1] << endl;
}
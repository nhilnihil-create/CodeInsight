#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    int N; cin >> N;
    string S, T;
    unordered_map<string, bool> Map;
    for (int i = 0; i < N; ++i) {
        if (i == 0) {
            cin >> T;
            Map[T] = true;
        }
        else {
            S = T; cin >> T;
            if (S[S.length() - 1] != T[0]) {
                printf("%s\n", "No"); return 0;
            }
            if (Map[T] == true) {
                printf("%s\n", "No"); return 0;
            }
            else Map[T] = true;
        }
    }
    printf("%s\n", "Yes");
    return 0;
}

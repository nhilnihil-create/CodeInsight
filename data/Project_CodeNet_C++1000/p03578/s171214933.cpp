#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    unordered_map<int, int> Map_D;
    unordered_map<int, int> Map_T;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        Map_D[a]++;
    }
    int M; cin >> M;
    vector<int> T(M, 0);
    for (int i = 0; i < M; i++) {
        cin >> T[i];
        Map_T[T[i]]++;
    }
    for (int i = 0; i < M; i++) {
        if (Map_T[T[i]] > Map_D[T[i]]) {
            cout << "NO" << endl; return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}

#include<iostream>
using namespace std;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    int ans = 0;
    for (int i = 1; i < N; i++) {
        bool memory_left[150] = {false};
        bool memory_right[150] = {false};
        int counter = 0;
        string left_S = S.substr(0, i);
        string right_S = S.substr(i, N - i);
        for (int j = 0; j < i; j++) {
            memory_left[int(left_S[j])] = true;
        }
        for (int j = 0; j < N - i; j++) {
            memory_right[int(right_S[j])] = true;
        }
        for (int j = 0; j < 150; j++) {
            if (memory_left[j] && memory_right[j]) {
                counter++;
            }
        }
        ans = max(ans, counter);
    }
    cout << ans << endl;
}

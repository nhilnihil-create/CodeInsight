#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int left = 0;
    int right = 0;
    int count[N];
    for (int i = 1; i < N; i++) {
        if (S[i] == 'E') right++;
    }
    count[0] = left + right;
    for (int i = 1; i < N; i++) {
        if (S[i - 1] == 'W') left++;
        if (S[i] == 'E') right--;
        count[i] = left + right;
    }
    int count_min = 999999;
    for (int i = 0; i < N; i++) {
        count_min = min(count_min, count[i]);
    }
    cout << count_min << endl;
}
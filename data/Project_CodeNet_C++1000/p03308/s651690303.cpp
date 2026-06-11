#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int minimum = 2000000000, maximum = 0; // 十分小さな値と十分大きな値

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        minimum = min(minimum, tmp);
        maximum = max(maximum, tmp);
    }
    
    cout << maximum - minimum << endl;
    return 0;
}
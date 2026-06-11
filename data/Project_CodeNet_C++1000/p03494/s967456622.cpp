#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int sum = 30; // log_2(10^9)=29.89...

    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        int temp = 0;

        int j = 0;
        while (j == 0) {
            if (A % 2 == 0) {
                temp++;
                A /= 2;
            }
            else {
                j = 1;
            }
        }

        sum = min(temp, sum);
    }
    cout << sum << endl;
    
}

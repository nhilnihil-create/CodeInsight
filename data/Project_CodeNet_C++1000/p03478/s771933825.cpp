#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int findSumOfDigits(int n) {
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main() {
    int N, A, B;
    cin >> N >> A >> B;
    int res = 0;
    REP(i, N) {
        int I = i+1;
        int sum = findSumOfDigits(I);
        if (sum >= A && sum <= B) {
            res += I;
        }
    }
    cout << res << endl;
}

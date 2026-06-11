#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    int count = 0;
    int sum = 0;

    for(int i=1; i <= N; i++) {
        int dig_sum = 0;
        int num = i;
        while(num) {
            dig_sum += (num % 10);
            num /= 10;
        }
        if(dig_sum >= A && dig_sum <= B) sum += i;
    }
    cout << sum << endl;
}
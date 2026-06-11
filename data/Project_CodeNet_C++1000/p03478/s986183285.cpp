#include<bits/stdc++.h>
using namespace std;
int main() {
    int N, A, B;
    cin >> N >> A >> B;
    int rel = 0;

    for (int i  = 1; i <= N; i++) {
        int j = i;
        int sum = 0;
        while(j > 0) {
            sum += j % 10;
            j /= 10;
        }

        if (sum >= A && sum <= B) {
            rel += i;
        }
    }

    cout << rel << endl;
}
#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int N; cin >> N;
    long long int ans = 0;
    for (int i = 1; i <= N; i++) {
        int sq_num = pow(i, 2);
        if (sq_num <= N) {
            ans = sq_num;
        } else {
            break;
        }
    }
    cout << ans << endl;
}


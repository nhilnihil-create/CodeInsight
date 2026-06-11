#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;
    int ans;
    for (int i = 1; i <= 9; i++) {
        ans = 111 * i;
        if (N <= ans) break;
    }
    cout << ans << endl;
}
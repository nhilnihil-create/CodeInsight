#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    if (N == 1) cout << "Hello World\n";
    else {
        int A, B; cin >> A >> B;
        cout << A + B << "\n";
    }
}
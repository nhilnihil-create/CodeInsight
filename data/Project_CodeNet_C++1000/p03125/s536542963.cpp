#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B; cin >> A >> B;
    cout << (B % A ? B - A : A + B) << "\n";
}
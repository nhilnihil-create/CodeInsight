#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    int difference = B - A;
    int ans = 0;
    for(int i = 1; i <= difference;i++) ans += i;

    cout << ans-B << endl;
}
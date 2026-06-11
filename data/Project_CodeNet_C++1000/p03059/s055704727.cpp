#include <iostream>

#define endl '\n'
#define ll long long

using namespace std;

int main() {
    int A, B, T;
    int sum = 0;

    cin >> A >> B >> T;

    sum = (T + 1/2) / A * B; 

    cout << sum << endl;

    return 0;
}
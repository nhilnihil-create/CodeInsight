#include <iostream>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    int mul = 1;
    for (int i = 0; i < M; i++) mul *= 2;
    int X = 100 * (N - M) * mul + 1900 * M *  mul;
    cout << X << endl;
}
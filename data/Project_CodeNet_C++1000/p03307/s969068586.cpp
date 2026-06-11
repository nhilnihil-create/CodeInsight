#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int count = 2;
    while((N % 2) != 0) {
        N *= count++;
    }
    cout << N << endl;
}
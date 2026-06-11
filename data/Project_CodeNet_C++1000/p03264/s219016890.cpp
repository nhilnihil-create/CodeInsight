#include <iostream>
using namespace std;
int main() {
    int K; cin >> K;
    int cnt = ((K + 1) / 2) * (K / 2);
    printf("%d\n", cnt);
}
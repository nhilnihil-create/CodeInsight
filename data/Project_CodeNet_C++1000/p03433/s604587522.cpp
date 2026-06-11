#include <iostream>
using namespace std;
int main() {
    int N, A; cin >> N >> A;
    if (A >= N % 500) printf("%s\n", "Yes");
    else printf("%s\n", "No");
}
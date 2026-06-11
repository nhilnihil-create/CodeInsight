#include <iostream>
#include <set>
using namespace std;
int main() {
    int N, K; cin >> N >> K;
    if ((N + 1) / 2 >= K) printf("%s\n", "YES");
    else printf("%s\n", "NO");
}
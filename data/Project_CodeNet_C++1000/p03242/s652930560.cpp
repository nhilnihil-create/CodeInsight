#include <iostream>
using namespace std;
int main() {
    string N; cin >> N;
    for (char c : N) {
        if (c == '1') printf("%c", '9');
        else printf("%c", '1');
    }
    printf("\n");
}
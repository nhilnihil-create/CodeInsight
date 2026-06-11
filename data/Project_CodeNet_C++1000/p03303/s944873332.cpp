#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    string S; int w; cin >> S >> w;
    for (int i = 0; i < S.length(); i += w) printf("%c", S[i]);
    printf("\n");
}

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int sed(int N) {
    int a = N;
    int c = 0;
    bool b = true;
    while(b){
        if (a == 0) {
            b = false;
        }
        c += a % 10;
        a /= 10;
    }
    return c;
}
int main() {
    int N; cin >> N;
    if (N % sed(N) == 0) printf("%s\n", "Yes");
    else printf("%s\n", "No");
}

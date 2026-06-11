#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int a, b; cin >> a >> b;
    int sum = 0, tmp = b - a;
    for (int i = 1; i < tmp; i++) sum += i;
    printf("%d\n", sum - a);
}

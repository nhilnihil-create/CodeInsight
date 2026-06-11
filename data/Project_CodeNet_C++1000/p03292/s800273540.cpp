#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> in(3, 0); cin >> in[0] >> in[1] >> in[2];
    sort(in.begin(), in.end());
    printf("%d\n", (in[1] - in[0]) + (in[2] - in[1]));
}
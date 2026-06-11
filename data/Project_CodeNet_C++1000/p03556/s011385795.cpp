#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath> 

using namespace std;

int main() {
    int N;
    cin >> N;
    int ans = floor(sqrt(N));
    cout << ans * ans << endl;
    return 0;
}
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
int main() {
    int N; cin >> N;
    vector<int> L(N, 0);
    for (int i = 0; i < N; i++) cin >> L[i];
    sort(L.begin(), L.end(), greater<int>());
    int sum = 0;
    for (int i = 1; i < N; i++) sum += L[i];
    if (L[0] < sum) printf("%s\n", "Yes");
    else printf("%s\n", "No");
}

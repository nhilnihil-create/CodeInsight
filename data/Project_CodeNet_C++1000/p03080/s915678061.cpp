#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N; string S; cin >> N >> S;
    int cnt = 0;
    for (char c : S) if (c == 'R') cnt++;
    if (cnt > N - cnt) printf("%s\n", "Yes");
    else printf("%s\n", "No");
}

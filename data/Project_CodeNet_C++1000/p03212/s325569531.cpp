#include <iostream>
using namespace std;
long long N, ans;

void dfs(long long x, int use) {
    if (x > N) return;
    if (use == 0b111) ans++;
    dfs(10 * x + 7, use | 0b100);
    dfs(10 * x + 5, use | 0b010);
    dfs(10 * x + 3, use | 0b001);
} 

int main() {
    cin >> N >> ans;
    dfs(0, 0);
    cout << ans << endl;
}
#include <iostream>
using namespace std;
int main() {
    int N, A, B; cin >> N >> A >> B;
    int ans_min = 0, ans_max = min(A, B);
    if (A + B > N) ans_min = max((N - max(A, B)), min(A, B)) - min((N - max(A, B)), min(A, B));
    printf("%d %d\n", ans_max, ans_min);
}
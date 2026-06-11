#include <iostream>
using namespace std;
int main() {
    int A, B; cin >> A >> B;
    int ans = 0;
    for (int i = 0; i < 2; i++)
    {
        ans += max(A, B);
        if (A > B) A--;
        else B--;
    }
    printf("%d\n", ans);
}
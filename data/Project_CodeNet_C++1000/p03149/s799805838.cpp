#include <iostream>
using namespace std;
int main() {
    int A[4]; cin >> A[0] >> A[1] >> A[2] >> A[3];
    int cnt_1 = 0, cnt_9 = 0, cnt_7 = 0, cnt_4 = 0;
    for (int x : A) {
        if (x == 1) cnt_1++;
        if (x == 9) cnt_9++;
        if (x == 7) cnt_7++;
        if (x == 4) cnt_4++;
    }
    if (cnt_1 == 1 && cnt_1 == cnt_9 && cnt_9 == cnt_7 && cnt_7 == cnt_4) printf("%s\n", "YES");
    else printf("%s\n", "NO");
}
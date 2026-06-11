#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int64_t X,Y;
    int cnt = 0;
    int64_t target;
    cin >> X >> Y;

    target = Y/X;
//printf("target:%ld\n", target);
    for(int64_t i=0;i<61;i++) {
//printf("cur:%ld\n", ((int64_t)1<<i));
        if(((int64_t)1<<i) <= target) {
            cnt++;
        } else {
            break;
        }
    }

    cout << cnt << endl;
    return 0;
}

#include <iostream>
#include <math.h>

using namespace std;

int main(void) {

    long long N, P;
    cin >> N;
    cin >> P;

    long long ans = 1;
    int i;

    if (N == 1){
        ans = P;
    }else{
        for (i = 2; i <= 1000010; i++) {
            long long kn = pow(i, N);
            if ((P % kn) == 0) {
                ans = i;
            }
            if (P < kn) {
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

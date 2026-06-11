#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int T, A;
    cin >> T >> A;
    double H[1100];
    double tmp[1100];
    double min = 10000;
    int ans;
    for(int i = 0; i < N; i++) {
        cin >> H[i];
        if(T - H[i]*0.006 > A) {
            tmp[i] = T - H[i]*0.006 - A;
        } else {
            tmp[i] = A - (T - H[i]*0.006);
        }
        if(min > tmp[i]) {
            min = tmp[i];
            ans = i + 1;
        }
    }
    cout << ans << endl;
}
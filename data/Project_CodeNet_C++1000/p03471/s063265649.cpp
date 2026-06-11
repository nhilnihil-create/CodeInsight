#include <iostream>
using namespace std;

int main()
{
    int n, y;
    cin >> n >> y;
    int ans10000 = -1, ans5000 = -1, ans1000 = -1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j + i <= n; j++) {
            int k = n - i  - j;
            if ((i*10000 + j*5000 + k*1000) ==y) {
                ans10000 = i;
                ans5000  = j;
                ans1000  = k;
                break;
            }
        }
    }

    cout << ans10000 << " " << ans5000 << " " << ans1000 << endl;
}
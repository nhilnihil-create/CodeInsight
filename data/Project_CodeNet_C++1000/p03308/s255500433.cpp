#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N; 
    cin >> N;
    int a[110];
    for (int i = 0; i < N; i++) cin >> a[i];

    int ans = 0;

    for (int i = 0; i < N; i++) {
        int num = 0;
        for (int j = 0; j < N; j++) {
            num = abs(a[i] - a[j]);
            ans = max(ans, num);
        }
    }

    cout << ans << endl;
}
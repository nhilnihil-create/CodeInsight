#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int t[102], v[102];
    t[0] = 0;
    for(int i = 0; i < n; i++){
        cin >> t[i + 1];
        t[i + 1] *= 2;
        t[i + 1] += t[i];
    }
    for(int i = 0; i < n; i++){
        cin >> v[i];
        v[i] *= 2;
    }
    int b[50000];
    for(int i = 0; i <= t[n]; i++) b[i] = min(i, t[n] - i);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < t[i]; j++) b[j] = min(b[j], v[i] + t[i] - j);
        for(int j = t[i]; j < t[i + 1]; j++) b[j] = min(b[j], v[i]);
        for(int j = t[i + 1]; j <= t[n]; j++) b[j] = min(b[j], v[i] + j - t[i + 1]);
    }
    int ans = 0;
    for(int i = 0; i < t[n]; i++) ans += b[i] + b[i + 1];
    cout << fixed << setprecision(15) << ans / 8.0 << endl;
}

#include <iostream>
using namespace std;
double myabs(double a) {
    if (a < 0) return -1 * a;
    return (double)a;
}
 
int main()
{
    int n, t, a;
    cin >> n >> t >> a;
    int h[n];
    for (int i = 0; i < n; i++) cin >> h[i];
    double diff = 0xffff;
    int p = -1;
 
    for (int i = 0; i < n; i++) {
        double temp = t - h[i] * 0.006;
        if (diff > myabs(a - temp)) {
            diff = myabs(a - temp);
            p = i + 1;
        }
    }
    cout << p << endl;
}
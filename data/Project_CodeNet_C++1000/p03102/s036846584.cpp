#include <iostream>
using namespace std;
int main() {
    int n, m, c;
    cin >> n >> m >> c;
    int b[m];
    for (int i=0; i<m; i++) {
        cin >> b[i];
    }
    int result = 0;
    for (int i=0; i<n; i++) {
        int sum = 0;
        for (int j=0; j<m; j++) {
            int a;
            cin >> a;
            sum += a*b[j];
        }
        if (sum+c > 0) {
            result++;
        }
    }
    cout << result << endl;
}
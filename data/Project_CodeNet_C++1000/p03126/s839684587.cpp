#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int like[m];
    for (int i=0; i<m; i++) {
        like[i] = 0;
    }
    for (int i=0; i<n; i++) {
        int k;
        cin >> k;
        for (int j=0; j<k; j++) {
            int a;
            cin >> a;
            like[a-1]++;
        }
    }
    int result = 0;
    for (int i=0; i<m; i++) {
        if (like[i] == n) {
            result++;
        }
    }
    cout << result << endl;
}
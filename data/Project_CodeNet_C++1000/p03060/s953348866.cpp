#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int v[n], c[n];
    int result = 0;
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    for (int i=0; i<n; i++) {
        cin >> c[i];
        result += max(v[i]-c[i], 0);
    }
    cout << result << endl;
}
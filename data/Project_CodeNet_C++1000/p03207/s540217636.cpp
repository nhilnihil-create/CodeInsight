#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int maxP = 100, result = 0;
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        result += p;
        maxP = max(maxP, p);
    }
    cout << result - maxP/2 << endl;
}
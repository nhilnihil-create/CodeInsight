#include <iostream>
using namespace std;
const int INF = 100000000;
int main() {
    int n ;
    cin >> n;
    int a[210];
    for (int i = 0; i< n; i++) cin >> a[i];

    int res = INF;

    for (int i = 0; i<n; i++) {
        int count = 0;

        while (a[i] % 2 == 0){
            a[i] /= 2;
            ++count;
        }

        if (res > count) res = count;
    }

    cout << res << endl;
}
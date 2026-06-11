#include<iostream>
using namespace std;

int main() {
    int n;
    int a[110];

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

  	int min_a = 1<<30, max_a = 0;
    for (int i = 0; i < n; i++) {
        min_a = min(min_a, a[i]);
        max_a = max(max_a, a[i]);
    }

    cout << max_a - min_a << endl;

}
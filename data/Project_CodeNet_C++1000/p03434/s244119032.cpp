#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[110];
    int N;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a, a+N);
    reverse(a, a+N);

    int A = 0, B = 0;
    for(int i = 0; i < N; i++) {
        if(i % 2 == 0) {
            A += a[i];
        } else {
            B += a[i];
        }
    }
    cout << A-B << endl;
}
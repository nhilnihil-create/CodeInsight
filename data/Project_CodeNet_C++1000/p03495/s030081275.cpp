#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int N, K;
    cin >> N >> K;
 
    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

   int SIZE = N + 1;
    int b[SIZE] = {0};
    for (int i = 0; i < N; i++) {
        b[a[i]]++;
    }
    sort(b, b + SIZE, greater<>());

#if 0
    cout << "sort :"; 
    for (int i  = 0; i < SIZE; i++) {
        cout << b[i];
    }
    cout << endl;
#endif

    int sum = 0;
    for (int i = K; i < SIZE; i++) {
        sum += b[i];
    }

    cout << sum << endl;

    return 0;
}
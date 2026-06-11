#include<bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    int a[N];
    int x[110] = {0};
    int count = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        x[a[i]]++;
    }

    for (int i = 0; i < 110; i++) {
        if (x[i])
            count++;
    }

    cout << count << endl;
}
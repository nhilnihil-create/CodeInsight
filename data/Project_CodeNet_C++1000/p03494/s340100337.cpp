#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int a[N];

    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int rel = 0;

    while(true) {
        bool hantei = false;
        for (int i = 0; i < N; i++) {
            if (a[i] % 2 != 0) hantei = true;
        }

        if (hantei == true) break;

        for (int i = 0; i < N; i++) {
            a[i] /= 2;
        }
        rel++;
    }

    cout << rel << endl;
}
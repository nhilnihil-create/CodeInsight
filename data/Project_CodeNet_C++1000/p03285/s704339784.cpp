#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    cin >> N;

    for(int i=0;i<=100;i+=4) {
        for(int j=0;j<=100;j+=7) {
            if((i+j) == N) {
                cout << "Yes\n";
                return 0;
            }
        }
    }

    cout << "No\n";
    return 0;
}

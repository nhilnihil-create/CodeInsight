#include <bits/stdc++.h>
using namespace std;

int main() {
    int X;
    cin >> X;
    int m = 0;

    for(int i=1; i<1000; i++) {
        for(int j=2; j<10; j++) {
            int a = pow(i, j);
            if(X >= a){
                m = max(m, a);
            }
        }
    }
    cout << m << endl;
}

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i=n; i>=1; i--) {
        if (sqrt(i)-floor(sqrt(i))==0) {
            cout << i << "\n";
            return 0;
        }
    }
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int d, n;
    cin>>d>>n;
    if (n != 100) {
        cout<<(int)(pow(100, d) * n)<<endl;
        return 0;
    } else {
        cout<<(int)(pow(100, d) * n) + (int)pow(100, d)<<endl;
    }
}

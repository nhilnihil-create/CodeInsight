#include <bits/stdc++.h>

using namespace std;

int main() {
    long long x,y,z;
    cin >> x >> y >> z;
    for(int i=0;i<10;i++){
        z = (x*z -y);
        cout << z << "\n";
    }
}
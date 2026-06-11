#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
    int a,b;
    cin >> a >> b;
    int x=1;
    for(int i = 0; i < b; i++) {
        x *= 2;
    }
    cout << ((a-b)*100+b*1900)*x << endl;

    return 0;
}
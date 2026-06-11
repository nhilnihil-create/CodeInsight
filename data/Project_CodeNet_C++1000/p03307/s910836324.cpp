#include <bits/stdc++.h>
using namespace std;

int64_t lcm(int a, int b) {
    return a/__gcd(a,b) * b;
}
int main(void) {
    int N;
    cin >> N;
    
    cout << lcm(2,N) << endl;
    return 0;
}

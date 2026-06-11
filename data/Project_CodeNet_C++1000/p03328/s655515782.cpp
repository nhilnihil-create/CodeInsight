#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long a, b;
    cin >> a >> b;

    long long n = b - a;
    long long ans = n*(n+1)/2 - b;

    cout << ans << endl;
    return 0;
}
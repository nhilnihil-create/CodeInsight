#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n;
    cin >> n;

    long long ans = 0;
    for(long long i = 1; i * i <= n; i++) ans = max(ans, i*i);

    cout << ans << endl;
    return 0;
}
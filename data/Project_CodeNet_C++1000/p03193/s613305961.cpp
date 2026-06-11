#include <iostream>
using namespace std;

int main() {
    long long n, h, w;
    cin >> n >> h >> w;
    long long ans = 0;
    while(n--){
        long long a, b;
        cin >> a >> b;
        if(h <= a && w <= b) ans++;
    }
    cout << ans;
    return 0;
}

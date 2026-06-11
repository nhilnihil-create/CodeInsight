#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    int k = 2 * N / K;
    int odd = (k + 1) / 2;
    int eve = k - odd;
    long ans = 0;
    ans += pow(eve, 3);
    if(K%2 == 0) ans += pow(odd, 3);
    cout << ans << endl;
    return 0;
}
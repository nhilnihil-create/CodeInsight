#include <iostream>
#include <vector>
using namespace std;
vector<bool> primeTable(int n) {
    vector<bool> prime(n + 1, true);
    if(n >= 0) prime[0] = false;
    if(n >= 1) prime[1] = false;
    for(int i = 2; i * i <= n; i++) {
        if(!prime[i]) continue;
        for(int j = i + i; j <= n; j += i) prime[j] = false;
    }
    return prime;
}
int main() {
    int N;
    cin >> N;
    auto p = primeTable(55555);
    for (int i = 1; i < 55555 && N > 0; i++) {
        if (p[i] && i % 5 == 1) {
            cout << i << " ";
            N--;
        }
    }
    cout << endl;
}
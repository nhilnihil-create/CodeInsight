#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

int main(void) {
    int N;cin>>N;
    ll result = 1;
    for (int i = 0; i < N; i++) {
        ll A;cin>>A;
        if (A % 2 == 0) result *= 2;
    }
    cout << pow(3, N) - result << endl;
    return 0;
}
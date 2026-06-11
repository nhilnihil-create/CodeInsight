#include <iostream>
#include <cstdlib>
#include <cmath>
typedef long long ll;
using namespace std;

int main(void) {
    ll A,B,C,K;
    cin>>A>>B>>C>>K;
    ll a = A;
    ll b = B;
    ll c = C;
    const ll th = pow(10, 18);
    ll result = (K % 2 == 0) ? a - b : b - a;
    if (abs(result) > th) cout << "Unfair" << endl;
    else cout << result << endl;
    return 0;
}
#include <iostream>
typedef long long ll;
using namespace std;

int main(void) {
    ll X,Y;cin>>X>>Y;
    int cnt = 0;
    while (X <= Y) {
        cnt++;
        X *= 2;
    }
    cout << cnt << endl;
    return 0;
}
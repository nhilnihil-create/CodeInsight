#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int64_t n,a,mina;
    int64_t times;
    cin >> n;

    mina = LONG_MAX;
    for(int i=0;i<5;i++) {
        cin >> a;
        if(mina > a) {
            mina = a;
        }
    }

    if(n%mina) {
        times = (n/mina) + 1;
    } else {
        times = n/mina;
    }

    times += 4;
    cout << times << endl;
    return 0;
}

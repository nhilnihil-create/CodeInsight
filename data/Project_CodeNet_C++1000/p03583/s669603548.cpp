#include<bits/stdc++.h>
using namespace std;

int main(void) {
    long N;
    cin >> N;
    for(long h=1; h<=3500; h++)
        for(long n=1; n<=3500; n++) {
            long w = roundl(1.0/(4.0/N - 1.0/h - 1.0/n));

            if(0 < w && w <= 3500 && abs(4.0/N - 1.0/h - 1.0/n - 1.0/w) < 1e-15) {
                cout << h << ' ' << n << ' ' << w << endl;
                return 0;
            }
        }

}

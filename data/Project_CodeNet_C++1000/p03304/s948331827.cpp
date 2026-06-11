#include<bits/stdc++.h>


int main(void) {
    using namespace std;

    long n, m, d;
    cin >> n >> m >> d;

    if(d > n-1) {
        cout << 0 << endl;
        return 0;
    }

    long k = n - d;
    double a = 1.0*(d==0?1:2)*k*(m-1);

    printf("%.16f\n", a / pow(1.0*n, 2.0));
}

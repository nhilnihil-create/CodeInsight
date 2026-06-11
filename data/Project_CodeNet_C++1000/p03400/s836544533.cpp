#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N,D,X;
    int d,a,sum=0;
    cin >> N >> D >> X;
    for(int i=0;i<N;i++) {
        cin >> a;
        for(int j=0;(j*a+1)<=D;j++) {
            sum++;
        }
    }

    cout << sum + X << endl;
    return 0;
}

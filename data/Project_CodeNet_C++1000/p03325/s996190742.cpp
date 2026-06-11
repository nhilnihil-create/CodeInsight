#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N,a;
    int sum = 0;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> a;
        while((a%2) == 0) {
            sum++;
            a/=2;
        }
    }

    cout << sum << endl;
    return 0;
}

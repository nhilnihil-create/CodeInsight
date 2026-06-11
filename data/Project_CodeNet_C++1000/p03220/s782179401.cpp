#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N,T,A;
    int h;
    int diff,pos,mindiff = INT_MAX;
    cin >> N >> T >> A;

    A *= 1000;
    T *= 1000;
    for(int i=0;i<N;i++) {
        cin >> h;
        diff = (T-h*6) - A;
        if(mindiff > abs(diff)) {
            mindiff = abs(diff);
            pos = i+1;
        }
    }
    
    cout << pos << endl;
    return 0;
}

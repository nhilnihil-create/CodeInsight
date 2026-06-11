#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N,X;
    int sum = 0;
    int minm=INT_MAX,m;
    cin >> N >> X;
    for(int i=0;i<N;i++) {
        cin >> m;
        sum += m;
        if(minm > m) {
            minm = m;
        }
    }

    cout << N + (X-sum)/minm << endl;
    return 0;
}

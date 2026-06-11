#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N,C;
    int sum = 0;
    
    cin >> N;
    vector<int> V(N);
    for(int i=0;i<N;i++) {
        cin >> V[i];
    }
    for(int i=0;i<N;i++) {
        cin >> C;
        if(V[i] > C) {
            sum += (V[i]-C);
        }
    }

    cout << sum << endl;
    return 0;
}

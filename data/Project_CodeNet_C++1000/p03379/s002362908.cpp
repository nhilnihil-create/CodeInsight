#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N,median,large,small;
    cin >> N;
    vector<int> X(N);
    vector<int> copy(N);

    for(int i=0;i<N;i++) {
        cin >> X[i];
    }

    copy = X;
    sort(copy.begin(), copy.end());
    median = copy[copy.size()/2-1];
    large = copy[copy.size()/2];
    for(int i=0;i<N;i++) {
        if(X[i] > median) {
            cout << median << endl;
        } else if(X[i] < median) {
            cout << large << endl;
        }else {
            if(large == median) {
                cout << median << endl;
            } else {
                cout << large << endl;
            }
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N,M;
    int sum = 0;
    cin >> N >> M;
    vector<int> X(M);
    vector<int> diff(M-1);
    for(int i=0;i<M;i++) {
        cin >> X[i];
    }
   
    if(N >= M){
        cout << "0\n";
        return 0;
    }

    sort(X.begin(), X.end());
    for(int i=1;i<M;i++){
        diff[i-1] = X[i]-X[i-1];
    }

    sort(diff.begin(), diff.end());
    for(int i=0;i<(M-N);i++) {
        sum += diff[i];
    }

    cout << sum << endl;
    return 0;
}

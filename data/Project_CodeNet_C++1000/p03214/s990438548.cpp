#include <bits/stdc++.h>

using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    int sum = 0;
    for (int i = 0; i < N; ++i){
        cin >> A[i];
        sum += A[i];
    }
    double ave = (double)(sum) / N;

    int ans = 0;
    double def1 = abs(ave - A[0]), def2;
    for (int i = 1; i < N; ++i) {
        def2 = abs(ave - A[i]);
        if(def1 > def2){
            ans = i;
            def1 = abs(ave - A[i]);
        }
    }

    cout << ans << endl;
    return 0;
}

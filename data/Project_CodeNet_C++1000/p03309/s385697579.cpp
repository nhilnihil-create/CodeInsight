#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long int> A(N);
    for(int n=0; n<N; n++) {
        cin >> A[n];
        A[n] -= (n+1);
    }

    sort(A.begin(), A.end());
    long long int ans=0;
    for(int n=0; n<N; n++) {
        ans += abs(A[n]-A[N/2]);
    }
    cout << ans << endl;


    return 0;
    
}
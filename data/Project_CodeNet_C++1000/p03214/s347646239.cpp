#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i=0; i<N; i++) {
        cin >> a[i];
    }
    double ave = accumulate(a.begin(), a.end(), 0.0) / N;
    int ans;
    double min_diff = 1.0e9;
    for(int i=0; i<N; i++) {
        if(abs(ave - a[i]) < min_diff) {
            min_diff = abs(ave - a[i]);
            ans = i;
        }       
    }

    cout << ans << endl;
    return 0;
}

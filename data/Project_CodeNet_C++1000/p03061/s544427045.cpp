#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {

    int N; cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    vector<int> left(N+1, 0), right(N+1, 0);

    for(int i = 0; i < N; i++)      left[i+1] = __gcd(a[i], left[i]);
    for(int i = N - 1; i >= 0; i--) right[i]  = __gcd(a[i], right[i+1]);


    // for (int i = 0; i < N; ++i) cout << left[i] << endl;
    // cout << endl;
    // for (int i = 0; i < N; ++i) cout << right[i] << endl;
    // cout << endl;

    int res = 0;
    for (int i = 0; i < N; ++i) {
        int l = left[i];
        int r = right[i+1];

        res = max(__gcd(l,r), res);
    }

    cout << res << endl;

    return 0;
}
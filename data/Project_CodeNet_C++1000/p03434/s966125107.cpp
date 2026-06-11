#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> vec(N);

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        vec.at(i) = x;
    }

    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());

    int sum_Alice = 0, sum_Bob = 0;

    if (N % 2 == 0) {
        for (int i = 0; i < N/2; i++) {
            sum_Alice += vec.at(2*i);
            sum_Bob += vec.at(2*i + 1);
        }
    }
    else {
        vec.push_back(0);
        for (int i = 0; i < N/2 + 1; i++) {
            sum_Alice += vec.at(2*i);
            sum_Bob += vec.at(2*i + 1);
        }
    }

    int ans;
    
    ans = sum_Alice - sum_Bob;
    cout << ans << endl;
}

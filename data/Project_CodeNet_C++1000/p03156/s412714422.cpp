#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N;
    cin >> N;
    int A, B;
    cin >> A >> B;
    vector<int> P(N);

    rep(i, N)
        cin >> P.at(i);
    
    int s = 0;
    int m = 0;
    int l = 0;

    rep(i, N) {
        if (P.at(i) <= A)
            s++;
        else if (P.at(i) <= B)
            m++;
        else
            l++;
    }

    cout << min(min(s, m), l);
}
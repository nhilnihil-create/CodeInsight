#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    
    vector<int> X(N), X2;
    for (int i = 0; i < N; i++)
    {
        cin >> X[i];
    }
    X2 = X;
    sort(X.begin(), X.end());
    int med_min, med_max;
    med_min = X[N/2-1];
    med_max = X[N/2];

    for (int i = 0; i < N; i++)
    {
        if (X2[i] <= med_min)
        {
            cout << med_max << endl;
        }
        else
        {
            cout << med_min << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    
    vector<int> X(N), Y;
    for (int i = 0; i < N; i++)
    {
        cin >> X[i];
    }
    Y = X;
    sort(Y.begin(), Y.end());

    for (int i = 0; i < N; i++)
    {
        if (X[i] <= Y[N/2-1])
        {
            cout << Y[N/2] << endl;
        }
        else
        {
            cout << Y[N/2-1] << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
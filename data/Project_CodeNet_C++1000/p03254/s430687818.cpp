#include <bits/stdc++.h>
using namespace std;


int main() {
    int N, x;
    cin >> N >> x;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        x -= A[i];
        if (x < 0)
            break;
        cnt++;
    }
    if (x > 0)
        cout << cnt-1 << endl;
    else
        cout << cnt << endl;
}
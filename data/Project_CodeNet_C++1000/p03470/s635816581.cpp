#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i<N; i++) {
        cin >> A[i];
    }
    sort(A.begin(),A.end());


    int num = 1;
    for (int i = 1; i < N; i++) {
        if (A[i] > A[i-1])
            num++;
    }

    cout << num << endl;

    return 0;
}

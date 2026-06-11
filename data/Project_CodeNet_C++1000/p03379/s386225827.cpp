#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> X(N);
    for(int i=0; i<N; i++) cin >> X[i];

    vector<int> A = X;
    sort(A.begin(), A.end());
    int mid1 = A[N/2-1];
    int mid2 = A[N/2];
    for(int i=0; i<N; i++)
    {
        if(X[i] <= mid1) cout << mid2 << endl;
        else cout << mid1 << endl;
    }

    return 0;
}

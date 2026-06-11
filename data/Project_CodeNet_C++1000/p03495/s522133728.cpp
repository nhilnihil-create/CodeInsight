#include <bits/stdc++.h>
using namespace std;
int N, K;

int main()
{
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    vector<int> bucket(202020);
    for (int i = 0; i < N; i++)
    {
        bucket[A[i]]++;
    }
    sort(bucket.begin(), bucket.end());
    reverse(bucket.begin(), bucket.end());

    int count = 0;
    for (int i = K; i < 202020; i++)
    {
        if (!bucket[i])
            break;
        count += bucket[i];
    }
    cout << count << endl;
}

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long N, M;
    cin >> N >> M;
    vector<pair<long long, long long>> A(N);
    for (long long i = 0; i < N; i++)
    {
        long long a;
        cin >> a;
        A[i] = make_pair(a, 1);
    }
    for (long long i = 0; i < M; i++)
    {
        long long b, c;
        cin >> b >> c;
        A.push_back(make_pair(c, b));

    }

    sort(A.begin(), A.end());

    long long ans = 0;
    long long i = A.size() - 1;
    long long x = 0;
    while(1)
    {
        if(x + A[i].second > N)
        {
            ans += A[i].first * (N - x);
            break;
        }
        ans += A[i].first * A[i].second;
        x += A[i].second;
        i--; 
    }
    cout << ans << endl;
}
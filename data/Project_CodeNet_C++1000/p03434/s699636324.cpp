#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define rep(i, s, e) for (int i = s; i < e; i++)
#define endl '\n'
int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,0,N)cin>>A[i];
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    int alice = 0;
    int bob = 0;
    rep(i, 0, N)
    {
        if (i % 2 == 0)
            alice += A[i];
        else
            bob += A[i];
    }
    cout << abs(alice - bob) << endl;
}
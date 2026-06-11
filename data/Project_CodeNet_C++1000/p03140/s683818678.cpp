#include <bits/stdc++.h>
#define rep(i, N) for (int i = 0; i < N; i++)
using namespace std;

int main()
{
    int N, count = 0;
    string A, B, C;
    set<char> s;
    cin >> N >> A >> B >> C;
    rep(i, N)
    {
        s.clear();
        s.insert(A[i]);
        s.insert(B[i]);
        s.insert(C[i]);
        count += (s.size() - 1);
    }
    cout << count << endl;
}
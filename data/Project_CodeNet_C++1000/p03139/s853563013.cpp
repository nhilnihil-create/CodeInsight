#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, A, B, m;
    cin >> N >> A >> B;
    if (A + B <= N)
    {
        m = 0;
    }
    else
    {
        m = (A + B) - N;
    }
    cout << min(A, B) << " " << m << endl;
}

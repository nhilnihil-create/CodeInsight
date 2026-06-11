#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)

int main()
{
    vector<int> A(4);
    cin >> A[0];
    cin >> A[1];
    cin >> A[2];
    cin >> A[3];
    sort(A.begin(), A.end());
    int temp = A[0] * 1000 + A[1] * 100 + A[2] * 10 + A[3];
    if (temp == 1479)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}
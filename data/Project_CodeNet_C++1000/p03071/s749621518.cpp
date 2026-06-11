#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int A, B;
    cin >> A >> B;
    cout << (A == B ? 2 * A : max(A, B) * 2 - 1) << endl;
    return 0;
}

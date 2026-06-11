#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int A, B;
    cin >> A >> B;
    ll answer = A;
    if (A > B)
    {
        answer--;
    }
    cout << answer << endl;
    return 0;
}
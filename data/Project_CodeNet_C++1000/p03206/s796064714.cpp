#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<string, int, int> TU;

int main()
{
    int A;
    cin >> A;
    cout << "Christmas ";
    rep0(i, 25 - A)
    {
        cout << "Eve ";
    }
}

#include <bits/stdc++.h>
using namespace std;
int N, A, B;
int main()
{
    cin >> N >> A >> B;
    int plan1 = N * A;
    cout << (plan1 < B ? plan1 : B) << endl;
    return 0;
}
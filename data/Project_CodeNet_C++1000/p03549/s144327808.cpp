#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll N,M;
    cin >> N >> M;

    ll timeSum = 1900 * M + 100 * (N-M);
    ll reversePropability = pow(2,M);

    cout << timeSum * reversePropability << endl;

    return 0;

}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int N,A,B;
    cin >> N >> A >>B;

    if((B-A)%2 == 0) cout << "Alice" << endl;
    else cout << "Borys" << endl;

    return 0;
}
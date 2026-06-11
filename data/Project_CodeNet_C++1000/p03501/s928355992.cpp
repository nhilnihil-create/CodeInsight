#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
    
int main()
{
    int N, A, B;
    cin >> N >> A >> B;

    int plan1 = N * A;
    int plan2 = B;

    if (plan1 < plan2) {
        cout << plan1;
    } else {
        cout << plan2;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)

int main()
{
    int N, A, B;
    cin >> N >> A >> B;
    int mini = 0;

    if (A + B >= N)
    {
        mini = (A + B) - N;
    }

    cout << min(A, B) << " " << mini << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long N, A, B, C, D, E;
    cin >> N >> A >> B >> C >> D >> E;

    vector<long> T ={ A, B, C, D, E };

    long T_min = *min_element(T.begin(), T.end());

    long cnt = 4 + N / T_min;
    if (N % T_min != 0) {
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}
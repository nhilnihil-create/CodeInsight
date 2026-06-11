#include <bits/stdc++.h>

using namespace std;
// ache o minimo int positivo divisivel por 2 e N
int main()
{
    ios::sync_with_stdio(false);
    int N;
    double i;
    cin >> N;
    i = N;
    while (1)
    {
        if ((i / 2) - (int(i) / 2) == 0 && (i / N) - (int(i) / N) == 0 && i != 0)
        {
            cout << "" << (int)i;
            break;
        }
        i += N;
        //cout << i << endl;
    }
    return 0;
}
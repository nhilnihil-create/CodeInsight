#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int N, a[109];
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    sort(a, a + N, greater<int>());

    int ret = 0,reet=0;

    for (int i = 0; i < N; i++)

        if (i % 2 == 0)
        {
            ret += a[i];
        }
        else
        {
            reet += a[i];
        }
    cout << ret-reet << endl;
    return 0;
}

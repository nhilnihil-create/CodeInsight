#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <numeric>
#include <set>
#include <list>
#include <bitset>
#include <cstdlib>
#include <map>
using ll = long long int;
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    float average = (float)accumulate(A.begin(), A.end(), 0) / N;
    float flag = 100;
    int ans = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        if (abs(average - A[i]) <= flag)
        {
            flag = abs(average - A[i]);
            ans = i;
        }
    }
    cout << ans << endl;

    return 0;
}
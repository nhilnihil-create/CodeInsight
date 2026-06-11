#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> A(2, vector<int>(N));
    for (int i = 0; i < N; ++i)
    {
        cin >> A[0][i];
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> A[1][i];
    }
    int candy = A[0][0] + accumulate(A[1].begin(), A[1].end(), 0);
    for (int i = 1; i < N; ++i)
    {
        candy = max(candy, accumulate(A[0].begin(), A[0].begin() + i + 1, 0) + accumulate(A[1].begin() + i, A[1].end(), 0));
    }
    cout << candy << endl;
}
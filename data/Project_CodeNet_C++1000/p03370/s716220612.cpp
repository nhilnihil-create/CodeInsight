#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main()
{
    int N, X;
    vector<int> M;
    cin >> N;
    cin >> X;
    for (int i = 0; i < N; ++i)
    {
        int m;
        cin >> m;
        M.push_back(m);
    }
    int sum, min, count;
    sum = accumulate(M.begin(), M.end(), 0);
    min = *min_element(M.begin(), M.end());
    X -= sum;
    count = X / min;
    cout << count + N << endl;
}
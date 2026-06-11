#include <iostream>
#include <vector>
#include <algorithm>

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

    int min = *min_element(A.begin(), A.end());
    int max = *max_element(A.begin(), A.end());

    cout << max - min;
}
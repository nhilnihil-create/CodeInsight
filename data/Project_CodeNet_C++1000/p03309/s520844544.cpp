#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    size_t N;
    cin >> N;

    vector<long> A(N, 0);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    vector<long> base(N, 0);
    for (int i = 0; i < N; ++i)
        base[i] = A[i] - (i + 1);
    sort(base.begin(), base.end());

    long b = base[N / 2];
    size_t out(0);
    
    for (auto x : base)
        out += static_cast<size_t>(abs(x - b));

    cout << out << endl;
}

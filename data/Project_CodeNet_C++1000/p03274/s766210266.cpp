#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, K;
    cin >> N >> K;
    vector<int> x;
    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        x.emplace_back(tmp);
    }

    int min = 2000000000;
    int d1, d2;
    for (int i = 0; i <= N - K; i++)
    {
        d1 = abs(x[i]) + abs(x[i] - x[i + K - 1]);
        d2 = abs(x[i + K - 1]) + abs(x[i + K - 1] - x[i]);
        if (d1 < min) min = d1;
        if (d2 < min) min = d2;
    }
    
    cout << min << endl;

    return 0;
}
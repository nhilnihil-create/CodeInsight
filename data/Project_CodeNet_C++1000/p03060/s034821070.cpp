#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<int> V, C;
    V.resize(N);
    C.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> V[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> C[i];
    }

    vector<int> d;
    d.resize(N);
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        d[i] = V[i] - C[i];
        if (d[i] > 0)
        {
            sum += d[i];
        }
        
    }
    
    cout << sum << endl;
    
    return 0;
}
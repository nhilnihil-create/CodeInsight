#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    map<int, int> D;
    int in;
    for (int i = 0; i < N; i++)
    {
        cin >> in;
        D[in]++;
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> in;
        D[in]--;
        if (D[in] < 0)
        {
            cout << "NO" << endl;
            return 0;
        }

    }

    cout << "YES" << endl;

    return 0;
}
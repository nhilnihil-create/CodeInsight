#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    int T, A;
    vector<int> H;
    cin >> N;
    cin >> T;
    cin >> A;
    for (int i = 0; i < N; ++i)
    {
        int h;
        cin >> h;
        H.push_back(h);
    }
    int ans = 0;
    float t = abs(A - T + H[0] * 0.006);
    for (int i = 0; i < N; ++i)
    {
        if (abs(A - T + H[i] * 0.006) < t)
        {
            t = abs(A - T + H[i] * 0.006);
            ans = i;
        }
    }
    cout << ans + 1 << endl;
}
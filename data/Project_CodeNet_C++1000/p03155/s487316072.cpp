#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, H, W;
    cin >> N >> H >> W;
    cout << max(0, N - H + 1) * max(0, N - W + 1) << endl;
    return 0;
}
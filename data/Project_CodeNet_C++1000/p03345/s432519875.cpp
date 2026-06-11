#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int A, B, C;
    long long K;
    cin >> A >> B >> C;
    cin >> K;
    int ans;
    if (K % 2 != 0)
    {
        ans = B - A;
    }else
    {
        ans = A - B;
    }

    cout << ans << endl;

    return 0;
}